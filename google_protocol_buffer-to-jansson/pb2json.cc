#include "pb2json.h"

string hexEncode(string binInput)
{
    string hexOutput;
    char hByte, lByte;

    for (size_t i = 0; i < binInput.length(); i++)
    {
        hByte = binInput[i];
        lByte = hByte & 0x0f;

        hByte += 0x30;
        lByte += 0x30;

        if (hByte > 0x39)
            hByte += 0x07;
        if (lByte > 0x39)
            lByte += 0x07;

        hexOutput.push_back(hByte);
        hexOutput.push_back(lByte);
    }

    return hexOutput;
}

json_t *parseFromRepeatField(const Message *msg,
                             const FieldDescriptor *field)
{
    const Reflection *ref = msg->GetReflection();
    json_t *json_arr = json_array();
    json_t *value = json_object();
    int size = ref->FieldSize(*msg, field);

    if (ref == NULL || json_arr == NULL)
        return NULL;

    switch (field->cpp_type())
    {

#define _GET_REPEAT_VALUE(cpptype, vtype, ctype, jsontype)        \
    case FieldDescriptor::CPPTYPE_##cpptype:                      \
    {                                                             \
        for (int i = 0; i < size; i++)                            \
        {                                                         \
            vtype get##ctype;                                     \
            get##ctype = ref->GetRepeated##ctype(*msg, field, i); \
            value = jsontype(get##ctype);                         \
            json_array_append_new(json_arr, value);               \
        }                                                         \
        break;                                                    \
    }

        _GET_REPEAT_VALUE(DOUBLE, double, Double, json_real);
        _GET_REPEAT_VALUE(FLOAT, float, Float, json_real);
        _GET_REPEAT_VALUE(INT32, int32_t, Int32, json_integer);
        _GET_REPEAT_VALUE(INT64, int64_t, Int64, json_integer);
        _GET_REPEAT_VALUE(UINT32, uint32_t, UInt32, json_integer);
        _GET_REPEAT_VALUE(UINT64, uint64_t, UInt64, json_integer);

#undef _GET_REPEAT_VALUE

    case FieldDescriptor::CPPTYPE_BOOL:
        for (int i = 0; i < size; i++)
        {
            bool getBool;
            getBool = ref->GetRepeatedBool(*msg, field, i);
            if (getBool)
                value = json_true();
            else
                value = json_false();
            json_array_append_new(json_arr, value);
        }
        break;

    case FieldDescriptor::CPPTYPE_ENUM:
        for (int i = 0; i < size; i++)
        {
            const EnumValueDescriptor *getEnum;
            getEnum = ref->GetRepeatedEnum(*msg, field, i);
            //value = json_integer(getEnum->number());
            value = json_string(getEnum->name().c_str());
            json_array_append_new(json_arr, value);
        }
        break;

    case FieldDescriptor::CPPTYPE_MESSAGE:
        for (int i = 0; i < size; i++)
        {
            const Message *subMsg;
            subMsg = &ref->GetRepeatedMessage(*msg, field, i);
            if (subMsg->ByteSizeLong())
            {
                value = parseFromMsg(subMsg);
                json_array_append_new(json_arr, value);
            }
        }
        break;

    case FieldDescriptor::CPPTYPE_STRING:
    {
        for (int i = 0; i < size; i++)
        {
            string hexStr;
            string getString;
            getString = ref->GetRepeatedString(*msg, field, i);
            switch (field->type())
            {
            case FieldDescriptor::TYPE_STRING:
                value = json_string(getString.c_str());
                break;

            case FieldDescriptor::TYPE_BYTES:
                hexStr = hexEncode(getString);
                value = json_string(hexStr.c_str());
                break;

            default:
                break;
            }
            json_array_append_new(json_arr, value);
        }
    }

    break;

    default:
        break;
    }

    return json_arr;
}

json_t *parseFromMsg(const Message *msg)
{
    const Descriptor *descriptor = msg->GetDescriptor();
    const Reflection *ref = msg->GetReflection();
    json_t *json_obj = json_object();

    if (descriptor == NULL || ref == NULL)
        return NULL;

    for (int i = 0; i < descriptor->field_count(); i++)
    {
        const FieldDescriptor *field = descriptor->field(i);
        json_t *value = json_object();

        if ((!field->is_repeated() && ref->HasField(*msg, field)) ||
            (field->is_repeated() && ref->FieldSize(*msg, field)))
        {

            const char *field_name = field->name().c_str();

            double getDouble;
            float getFloat;
            int32_t getInt32;
            int64_t getInt64;
            uint32_t getUInt32;
            uint64_t getUInt64;
            bool getBool;
            const EnumValueDescriptor *getEnum;
            const Message *subMsg;
            string getString, hexStr;

            if (field->is_repeated() == true)
            {
                json_t *repeat_field = parseFromRepeatField(msg, field);
                json_object_set_new(json_obj, field_name, repeat_field);
            }
            else
            {
                switch (field->cpp_type())
                {

#define _GETVALUE(cpptype, ctype, jsontype)        \
    case FieldDescriptor::CPPTYPE_##cpptype:       \
    {                                              \
        get##ctype = ref->Get##ctype(*msg, field); \
        value = jsontype(get##ctype);              \
        break;                                     \
    }

                    _GETVALUE(DOUBLE, Double, json_real);
                    _GETVALUE(FLOAT, Float, json_real);
                    _GETVALUE(INT32, Int32, json_integer);
                    _GETVALUE(INT64, Int64, json_integer);
                    _GETVALUE(UINT32, UInt32, json_integer);
                    _GETVALUE(UINT64, UInt64, json_integer);

#undef _GETVALUE
                case FieldDescriptor::CPPTYPE_BOOL:
                    getBool = ref->GetBool(*msg, field);
                    if (getBool)
                        value = json_true();
                    else
                        value = json_false();
                    break;

                case FieldDescriptor::CPPTYPE_ENUM:
                    getEnum = ref->GetEnum(*msg, field);
                    //value = json_integer(getEnum->number());
                    value = json_string(getEnum->name().c_str());
                    break;

                case FieldDescriptor::CPPTYPE_MESSAGE:
                    subMsg = &ref->GetMessage(*msg, field);
                    value = parseFromMsg(subMsg);
                    break;

                case FieldDescriptor::CPPTYPE_STRING:
                {
                    getString = ref->GetString(*msg, field);

                    switch (field->type())
                    {
                    case FieldDescriptor::TYPE_STRING:
                        value = json_string(getString.c_str());
                        break;

                    case FieldDescriptor::TYPE_BYTES:
                        hexStr = hexEncode(getString);
                        value = json_string(hexStr.c_str());
                        break;

                    default:
                        break;
                    }
                    break;
                }

                default:
                    break;
                }
                json_object_set_new(json_obj, field_name, value);
            }
        }
    }

    return json_obj;
}

char *pb2json(Message *msg, char *buffer)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::string str(buffer, sizeof(buffer));
    msg->ParseFromString(str);
    json_t *json_obj = parseFromMsg(msg);
    char *writeIntoJson = json_dumps(json_obj, JSON_PRESERVE_ORDER);

    //free(writeIntoJson);
    json_decref(json_obj);
    return writeIntoJson;
}

char *pb2json(const Message *msg)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    json_t *json_obj = parseFromMsg(msg);
    char *writeIntoJson = json_dumps(json_obj, JSON_PRESERVE_ORDER);

    // free(writeIntoJson);
    json_decref(json_obj);
    return writeIntoJson;
}
