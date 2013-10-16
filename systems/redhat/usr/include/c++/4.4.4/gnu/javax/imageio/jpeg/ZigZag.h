
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_imageio_jpeg_ZigZag__
#define __gnu_javax_imageio_jpeg_ZigZag__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace imageio
      {
        namespace jpeg
        {
            class ZigZag;
        }
      }
    }
  }
}

class gnu::javax::imageio::jpeg::ZigZag : public ::java::lang::Object
{

public:
  ZigZag();
  static JArray< jbyte > * encode(JArray< JArray< jbyte > * > *);
  static JArray< jdouble > * encode(JArray< JArray< jdouble > * > *);
  static JArray< jfloat > * encode(JArray< JArray< jfloat > * > *);
  static JArray< jshort > * encode(JArray< JArray< jshort > * > *);
  static JArray< JArray< jdouble > * > * decode(JArray< jdouble > *);
  static JArray< JArray< jbyte > * > * decode(JArray< jbyte > *);
  static JArray< JArray< jint > * > * decode(JArray< jint > *);
  static JArray< JArray< jbyte > * > * decode(JArray< jbyte > *, jint, jint);
  static JArray< JArray< jdouble > * > * decode(JArray< jdouble > *, jint, jint);
  static JArray< JArray< jfloat > * > * decode(JArray< jfloat > *, jint, jint);
  static JArray< JArray< jint > * > * decode(JArray< jint > *, jint, jint);
  static JArray< JArray< jdouble > * > * decode8x8_map(JArray< jdouble > *);
  static const jboolean ZIGZAG_FORWARD = 1;
  static const jboolean ZIGZAG_BACKWARD = 0;
  static JArray< jint > * ZIGZAG_8X8_MAP;
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_imageio_jpeg_ZigZag__
