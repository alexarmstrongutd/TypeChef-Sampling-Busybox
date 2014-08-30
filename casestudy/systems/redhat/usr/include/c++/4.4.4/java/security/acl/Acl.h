
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_security_acl_Acl__
#define __java_security_acl_Acl__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace security
    {
        class Principal;
      namespace acl
      {
          class Acl;
          class AclEntry;
          class Permission;
      }
    }
  }
}

class java::security::acl::Acl : public ::java::lang::Object
{

public:
  virtual ::java::lang::String * getName() = 0;
  virtual void setName(::java::security::Principal *, ::java::lang::String *) = 0;
  virtual jboolean addEntry(::java::security::Principal *, ::java::security::acl::AclEntry *) = 0;
  virtual jboolean removeEntry(::java::security::Principal *, ::java::security::acl::AclEntry *) = 0;
  virtual ::java::util::Enumeration * entries() = 0;
  virtual jboolean checkPermission(::java::security::Principal *, ::java::security::acl::Permission *) = 0;
  virtual ::java::util::Enumeration * getPermissions(::java::security::Principal *) = 0;
  virtual ::java::lang::String * toString() = 0;
  virtual jboolean addOwner(::java::security::Principal *, ::java::security::Principal *) = 0;
  virtual jboolean deleteOwner(::java::security::Principal *, ::java::security::Principal *) = 0;
  virtual jboolean isOwner(::java::security::Principal *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_security_acl_Acl__