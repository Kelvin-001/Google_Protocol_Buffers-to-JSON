#ifndef PB2JSON_H
#define PB2JSON_H

#include <string>

#include "google/protobuf/reflection.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/message.h"
#include "jansson.h"

using namespace std;
using namespace google::protobuf;

json_t *parseFromMsg(const Message *msg);

json_t *parseFromRepeatField(const Message *msg,
                             const FieldDescriptor *field);

string hexEncode(const string binInput);

char *pb2json(Message *msg, const char *buffer);

char *pb2json(const Message *msg);

#endif
