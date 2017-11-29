#ifndef PROTOBUFHELPER_H
#define PROTOBUFHELPER_H

#include "phonebook.pb.h"

#include <QByteArray>
#include <QVariantList>

class ProtobufHelper
{
public:
    void addRecord(stc::Message &message, QVariantList &data);
    stc::Person_Country stdStrToPersonCountry(std::string country);
    void addPerson(stc::Message &message, QVariantList &data);
    QVariantList getPersonData(stc::Message &message, int index);
    void addClient(stc::Message &message, QVariantList &clientList);
    QVariantList getClientData(stc::Message &message, int index);
};

#endif // PROTOBUFHELPER_H
