
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_print_ipp_attribute_UnknownAttribute__
#define __gnu_javax_print_ipp_attribute_UnknownAttribute__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace print
      {
        namespace ipp
        {
          namespace attribute
          {
              class UnknownAttribute;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace net
    {
        class URI;
    }
  }
}

class gnu::javax::print::ipp::attribute::UnknownAttribute : public ::java::lang::Object
{

public:
  UnknownAttribute(jbyte, ::java::lang::String *, JArray< jbyte > *);
  ::java::lang::Class * getCategory();
  ::java::lang::String * getName();
  jbyte getValueTag();
  ::java::lang::String * getAttributeName();
  JArray< jbyte > * getAttributeValue();
  ::java::lang::String * getAttributeValueAsString();
  jint getAttributeValueAsInt();
  ::java::net::URI * getAttributeValueAsUri();
  ::java::lang::String * toString();
private:
  jbyte __attribute__((aligned(__alignof__( ::java::lang::Object)))) tag;
  ::java::lang::String * name;
  JArray< jbyte > * value;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_print_ipp_attribute_UnknownAttribute__
