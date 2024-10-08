#ifdef SOUP_BUILD
module;
#endif

#include "sha.h"
#include <iostream>
#include "base64.h"

#ifdef SOUP_BUILD
export module CryptoPP;
#endif

#include "Interface.h"

std::string CryptoPP::Sha1::HashBase64(std::string value)
{
    #pragma warning(push)
    #pragma warning(disable : 4127)

    std::string digest;
    CryptoPP::SHA1 hash;
    hash.Update((const byte*)value.data(), value.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*)&digest[0]);

    std::string encoded;

    auto ss = CryptoPP::StringSource(
        (const byte*)digest.data(),
        digest.size(),
        true,
        new CryptoPP::Base64URLEncoder(new CryptoPP::StringSink(encoded)));

    #pragma warning(pop)

    return encoded;
}

std::string CryptoPP::Sha3_256::HashBase64(std::string value)
{
    std::string digest;

    #pragma warning(push)
    #pragma warning(disable : 4127)

    CryptoPP::SHA256 hash;
    hash.Update((const byte*)value.data(), value.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*)&digest[0]);

    std::string encoded;

    auto ss = CryptoPP::StringSource(
        (const byte*)digest.data(),
        digest.size(),
        true,
        new CryptoPP::Base64URLEncoder(new CryptoPP::StringSink(encoded)));

    #pragma warning(pop)

    return encoded;
}