#pragma once

#ifdef SOUP_BUILD
export
#endif
namespace CryptoPP
{
    class Sha1
    {
    public:
        /// <summary>
        /// Hash the input value
        /// </summary>
        static std::string HashBase64(std::string value);
    };

    class Sha3_256
    {
    public:
        /// <summary>
        /// Hash the input value
        /// </summary>
        static std::string HashBase64(std::string value);
    };
}