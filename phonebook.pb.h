// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: phonebook.proto

#ifndef PROTOBUF_phonebook_2eproto__INCLUDED
#define PROTOBUF_phonebook_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace stc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_phonebook_2eproto();
void protobuf_AssignDesc_phonebook_2eproto();
void protobuf_ShutdownFile_phonebook_2eproto();

class Person;
class Client;
class Message;

enum Person_Country {
  Person_Country_Russia = 8,
  Person_Country_USA = 1,
  Person_Country_Ukraine = 38
};
bool Person_Country_IsValid(int value);
const Person_Country Person_Country_Country_MIN = Person_Country_USA;
const Person_Country Person_Country_Country_MAX = Person_Country_Ukraine;
const int Person_Country_Country_ARRAYSIZE = Person_Country_Country_MAX + 1;

const ::google::protobuf::EnumDescriptor* Person_Country_descriptor();
inline const ::std::string& Person_Country_Name(Person_Country value) {
  return ::google::protobuf::internal::NameOfEnum(
    Person_Country_descriptor(), value);
}
inline bool Person_Country_Parse(
    const ::std::string& name, Person_Country* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Person_Country>(
    Person_Country_descriptor(), name, value);
}
// ===================================================================

class Person : public ::google::protobuf::Message {
 public:
  Person();
  virtual ~Person();

  Person(const Person& from);

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Person& default_instance();

  void Swap(Person* other);

  // implements Message ----------------------------------------------

  Person* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Person& from);
  void MergeFrom(const Person& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Person_Country Country;
  static const Country Russia = Person_Country_Russia;
  static const Country USA = Person_Country_USA;
  static const Country Ukraine = Person_Country_Ukraine;
  static inline bool Country_IsValid(int value) {
    return Person_Country_IsValid(value);
  }
  static const Country Country_MIN =
    Person_Country_Country_MIN;
  static const Country Country_MAX =
    Person_Country_Country_MAX;
  static const int Country_ARRAYSIZE =
    Person_Country_Country_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Country_descriptor() {
    return Person_Country_descriptor();
  }
  static inline const ::std::string& Country_Name(Country value) {
    return Person_Country_Name(value);
  }
  static inline bool Country_Parse(const ::std::string& name,
      Country* value) {
    return Person_Country_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required uint64 phone = 2;
  inline bool has_phone() const;
  inline void clear_phone();
  static const int kPhoneFieldNumber = 2;
  inline ::google::protobuf::uint64 phone() const;
  inline void set_phone(::google::protobuf::uint64 value);

  // required .stc.Person.Country country = 3;
  inline bool has_country() const;
  inline void clear_country();
  static const int kCountryFieldNumber = 3;
  inline ::stc::Person_Country country() const;
  inline void set_country(::stc::Person_Country value);

  // @@protoc_insertion_point(class_scope:stc.Person)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_phone();
  inline void clear_has_phone();
  inline void set_has_country();
  inline void clear_has_country();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* name_;
  ::google::protobuf::uint64 phone_;
  int country_;
  friend void  protobuf_AddDesc_phonebook_2eproto();
  friend void protobuf_AssignDesc_phonebook_2eproto();
  friend void protobuf_ShutdownFile_phonebook_2eproto();

  void InitAsDefaultInstance();
  static Person* default_instance_;
};
// -------------------------------------------------------------------

class Client : public ::google::protobuf::Message {
 public:
  Client();
  virtual ~Client();

  Client(const Client& from);

  inline Client& operator=(const Client& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Client& default_instance();

  void Swap(Client* other);

  // implements Message ----------------------------------------------

  Client* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Client& from);
  void MergeFrom(const Client& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // required string status = 2;
  inline bool has_status() const;
  inline void clear_status();
  static const int kStatusFieldNumber = 2;
  inline const ::std::string& status() const;
  inline void set_status(const ::std::string& value);
  inline void set_status(const char* value);
  inline void set_status(const char* value, size_t size);
  inline ::std::string* mutable_status();
  inline ::std::string* release_status();
  inline void set_allocated_status(::std::string* status);

  // @@protoc_insertion_point(class_scope:stc.Client)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_status();
  inline void clear_has_status();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* name_;
  ::std::string* status_;
  friend void  protobuf_AddDesc_phonebook_2eproto();
  friend void protobuf_AssignDesc_phonebook_2eproto();
  friend void protobuf_ShutdownFile_phonebook_2eproto();

  void InitAsDefaultInstance();
  static Client* default_instance_;
};
// -------------------------------------------------------------------

class Message : public ::google::protobuf::Message {
 public:
  Message();
  virtual ~Message();

  Message(const Message& from);

  inline Message& operator=(const Message& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Message& default_instance();

  void Swap(Message* other);

  // implements Message ----------------------------------------------

  Message* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message& from);
  void MergeFrom(const Message& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .stc.Client clientRecord = 1;
  inline int clientrecord_size() const;
  inline void clear_clientrecord();
  static const int kClientRecordFieldNumber = 1;
  inline const ::stc::Client& clientrecord(int index) const;
  inline ::stc::Client* mutable_clientrecord(int index);
  inline ::stc::Client* add_clientrecord();
  inline const ::google::protobuf::RepeatedPtrField< ::stc::Client >&
      clientrecord() const;
  inline ::google::protobuf::RepeatedPtrField< ::stc::Client >*
      mutable_clientrecord();

  // repeated .stc.Person personRecord = 2;
  inline int personrecord_size() const;
  inline void clear_personrecord();
  static const int kPersonRecordFieldNumber = 2;
  inline const ::stc::Person& personrecord(int index) const;
  inline ::stc::Person* mutable_personrecord(int index);
  inline ::stc::Person* add_personrecord();
  inline const ::google::protobuf::RepeatedPtrField< ::stc::Person >&
      personrecord() const;
  inline ::google::protobuf::RepeatedPtrField< ::stc::Person >*
      mutable_personrecord();

  // @@protoc_insertion_point(class_scope:stc.Message)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::stc::Client > clientrecord_;
  ::google::protobuf::RepeatedPtrField< ::stc::Person > personrecord_;
  friend void  protobuf_AddDesc_phonebook_2eproto();
  friend void protobuf_AssignDesc_phonebook_2eproto();
  friend void protobuf_ShutdownFile_phonebook_2eproto();

  void InitAsDefaultInstance();
  static Message* default_instance_;
};
// ===================================================================


// ===================================================================

// Person

// required string name = 1;
inline bool Person::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Person::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Person::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Person::clear_name() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Person::name() const {
  // @@protoc_insertion_point(field_get:stc.Person.name)
  return *name_;
}
inline void Person::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set:stc.Person.name)
}
inline void Person::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set_char:stc.Person.name)
}
inline void Person::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:stc.Person.name)
}
inline ::std::string* Person::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:stc.Person.name)
  return name_;
}
inline ::std::string* Person::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Person::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:stc.Person.name)
}

// required uint64 phone = 2;
inline bool Person::has_phone() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Person::set_has_phone() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Person::clear_has_phone() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Person::clear_phone() {
  phone_ = GOOGLE_ULONGLONG(0);
  clear_has_phone();
}
inline ::google::protobuf::uint64 Person::phone() const {
  // @@protoc_insertion_point(field_get:stc.Person.phone)
  return phone_;
}
inline void Person::set_phone(::google::protobuf::uint64 value) {
  set_has_phone();
  phone_ = value;
  // @@protoc_insertion_point(field_set:stc.Person.phone)
}

// required .stc.Person.Country country = 3;
inline bool Person::has_country() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Person::set_has_country() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Person::clear_has_country() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Person::clear_country() {
  country_ = 8;
  clear_has_country();
}
inline ::stc::Person_Country Person::country() const {
  // @@protoc_insertion_point(field_get:stc.Person.country)
  return static_cast< ::stc::Person_Country >(country_);
}
inline void Person::set_country(::stc::Person_Country value) {
  assert(::stc::Person_Country_IsValid(value));
  set_has_country();
  country_ = value;
  // @@protoc_insertion_point(field_set:stc.Person.country)
}

// -------------------------------------------------------------------

// Client

// required string name = 1;
inline bool Client::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Client::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Client::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Client::clear_name() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Client::name() const {
  // @@protoc_insertion_point(field_get:stc.Client.name)
  return *name_;
}
inline void Client::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set:stc.Client.name)
}
inline void Client::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set_char:stc.Client.name)
}
inline void Client::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:stc.Client.name)
}
inline ::std::string* Client::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:stc.Client.name)
  return name_;
}
inline ::std::string* Client::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Client::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:stc.Client.name)
}

// required string status = 2;
inline bool Client::has_status() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Client::set_has_status() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Client::clear_has_status() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Client::clear_status() {
  if (status_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    status_->clear();
  }
  clear_has_status();
}
inline const ::std::string& Client::status() const {
  // @@protoc_insertion_point(field_get:stc.Client.status)
  return *status_;
}
inline void Client::set_status(const ::std::string& value) {
  set_has_status();
  if (status_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    status_ = new ::std::string;
  }
  status_->assign(value);
  // @@protoc_insertion_point(field_set:stc.Client.status)
}
inline void Client::set_status(const char* value) {
  set_has_status();
  if (status_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    status_ = new ::std::string;
  }
  status_->assign(value);
  // @@protoc_insertion_point(field_set_char:stc.Client.status)
}
inline void Client::set_status(const char* value, size_t size) {
  set_has_status();
  if (status_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    status_ = new ::std::string;
  }
  status_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:stc.Client.status)
}
inline ::std::string* Client::mutable_status() {
  set_has_status();
  if (status_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    status_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:stc.Client.status)
  return status_;
}
inline ::std::string* Client::release_status() {
  clear_has_status();
  if (status_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = status_;
    status_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Client::set_allocated_status(::std::string* status) {
  if (status_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete status_;
  }
  if (status) {
    set_has_status();
    status_ = status;
  } else {
    clear_has_status();
    status_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:stc.Client.status)
}

// -------------------------------------------------------------------

// Message

// repeated .stc.Client clientRecord = 1;
inline int Message::clientrecord_size() const {
  return clientrecord_.size();
}
inline void Message::clear_clientrecord() {
  clientrecord_.Clear();
}
inline const ::stc::Client& Message::clientrecord(int index) const {
  // @@protoc_insertion_point(field_get:stc.Message.clientRecord)
  return clientrecord_.Get(index);
}
inline ::stc::Client* Message::mutable_clientrecord(int index) {
  // @@protoc_insertion_point(field_mutable:stc.Message.clientRecord)
  return clientrecord_.Mutable(index);
}
inline ::stc::Client* Message::add_clientrecord() {
  // @@protoc_insertion_point(field_add:stc.Message.clientRecord)
  return clientrecord_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::stc::Client >&
Message::clientrecord() const {
  // @@protoc_insertion_point(field_list:stc.Message.clientRecord)
  return clientrecord_;
}
inline ::google::protobuf::RepeatedPtrField< ::stc::Client >*
Message::mutable_clientrecord() {
  // @@protoc_insertion_point(field_mutable_list:stc.Message.clientRecord)
  return &clientrecord_;
}

// repeated .stc.Person personRecord = 2;
inline int Message::personrecord_size() const {
  return personrecord_.size();
}
inline void Message::clear_personrecord() {
  personrecord_.Clear();
}
inline const ::stc::Person& Message::personrecord(int index) const {
  // @@protoc_insertion_point(field_get:stc.Message.personRecord)
  return personrecord_.Get(index);
}
inline ::stc::Person* Message::mutable_personrecord(int index) {
  // @@protoc_insertion_point(field_mutable:stc.Message.personRecord)
  return personrecord_.Mutable(index);
}
inline ::stc::Person* Message::add_personrecord() {
  // @@protoc_insertion_point(field_add:stc.Message.personRecord)
  return personrecord_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::stc::Person >&
Message::personrecord() const {
  // @@protoc_insertion_point(field_list:stc.Message.personRecord)
  return personrecord_;
}
inline ::google::protobuf::RepeatedPtrField< ::stc::Person >*
Message::mutable_personrecord() {
  // @@protoc_insertion_point(field_mutable_list:stc.Message.personRecord)
  return &personrecord_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace stc

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::stc::Person_Country> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::stc::Person_Country>() {
  return ::stc::Person_Country_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_phonebook_2eproto__INCLUDED
