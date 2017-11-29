#include "protobufhelper.h"

#include <QDebug>

stc::Person_Country ProtobufHelper::stdStrToPersonCountry(std::string country)
{
    stc::Person_Country person_country;
    stc::Person_Country_Parse(country, &person_country);

    return person_country;
}

void ProtobufHelper::addRecord(stc::Message &message, QVariantList &data)
{
    if (data.size() == 2)
        addClient(message, data);
    else if (data.size() == 3)
        addPerson(message, data);
    else
        qDebug() << "Unknown message";
}

void ProtobufHelper::addPerson(stc::Message &message, QVariantList &personList)
{
    bool ok;
    auto person_country = stdStrToPersonCountry(personList[2].toString().toStdString());
    auto phone = personList[1].toString().toLong(&ok, 10);

    if (!ok)
        return;

    stc::Person *person = message.add_personrecord();
    person->set_name(personList[0].toString().toStdString());
    person->set_phone(phone);
    person->set_country(person_country);
}

QVariantList ProtobufHelper::getPersonData(stc::Message &message, int index)
{
    QVariantList personDataList;

    if( index >= message.personrecord_size())
        return personDataList;

    const stc::Person& person = message.personrecord(index);

    personDataList << QVariant(person.name().c_str())
                   << QString::number(person.phone())
                   << QString::fromStdString(stc::Person_Country_Name(person.country()));

    return personDataList;
}

void ProtobufHelper::addClient(stc::Message &message, QVariantList &personList)
{
    stc::Client *client = message.add_clientrecord();
    client->set_name(personList[0].toString().toStdString());
    client->set_status(personList[1].toString().toStdString());
}

QVariantList ProtobufHelper::getClientData(stc::Message &message, int index)
{
    QVariantList clientDataList;

    if( index >= message.clientrecord_size())
        return clientDataList;

    const stc::Client& client = message.clientrecord(index);

    clientDataList << QVariant(client.name().c_str())
                   << QVariant(client.status().c_str());

    return clientDataList;
}

