
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_crypto_jce_cipher_CipherAdapter__
#define __gnu_javax_crypto_jce_cipher_CipherAdapter__

#pragma interface

#include <javax/crypto/CipherSpi.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace crypto
      {
        namespace cipher
        {
            class IBlockCipher;
        }
        namespace jce
        {
          namespace cipher
          {
              class CipherAdapter;
          }
        }
        namespace mode
        {
            class IMode;
        }
        namespace pad
        {
            class IPad;
        }
      }
    }
  }
  namespace java
  {
    namespace security
    {
        class AlgorithmParameters;
        class Key;
        class SecureRandom;
      namespace spec
      {
          class AlgorithmParameterSpec;
      }
    }
  }
}

class gnu::javax::crypto::jce::cipher::CipherAdapter : public ::javax::crypto::CipherSpi
{

public: // actually protected
  CipherAdapter(::java::lang::String *, jint);
  CipherAdapter(::java::lang::String *);
  virtual void engineSetMode(::java::lang::String *);
  virtual void engineSetPadding(::java::lang::String *);
  virtual jint engineGetBlockSize();
  virtual jint engineGetOutputSize(jint);
  virtual JArray< jbyte > * engineGetIV();
  virtual ::java::security::AlgorithmParameters * engineGetParameters();
  virtual void engineInit(jint, ::java::security::Key *, ::java::security::SecureRandom *);
private:
  void engineInitHandler(jint, ::java::security::Key *, ::java::security::SecureRandom *);
public: // actually protected
  virtual void engineInit(jint, ::java::security::Key *, ::java::security::spec::AlgorithmParameterSpec *, ::java::security::SecureRandom *);
  virtual void engineInit(jint, ::java::security::Key *, ::java::security::AlgorithmParameters *, ::java::security::SecureRandom *);
  virtual JArray< jbyte > * engineUpdate(JArray< jbyte > *, jint, jint);
  virtual jint engineUpdate(JArray< jbyte > *, jint, jint, JArray< jbyte > *, jint);
  virtual JArray< jbyte > * engineDoFinal(JArray< jbyte > *, jint, jint);
  virtual jint engineDoFinal(JArray< jbyte > *, jint, jint, JArray< jbyte > *, jint);
private:
  void reset();
public: // actually protected
  ::gnu::javax::crypto::cipher::IBlockCipher * __attribute__((aligned(__alignof__( ::javax::crypto::CipherSpi)))) cipher;
  ::gnu::javax::crypto::mode::IMode * mode;
  ::gnu::javax::crypto::pad::IPad * pad;
  jint keyLen;
  ::java::util::Map * attributes;
  JArray< jbyte > * partBlock;
  jint partLen;
  jint blockLen;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_crypto_jce_cipher_CipherAdapter__
