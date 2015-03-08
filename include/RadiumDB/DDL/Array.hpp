#ifndef ZP_VARIANT_HPP
#define ZP_VARIANT_HPP

#include <RadonFramework/Radon.hpp>

namespace ZeroPrime {

struct Variant
{
    union
    {
        RF_Type::Int64 Integer;
        RF_Type::Float32 Float;
        RF_Type::UInt64 String;
        RF_Type::Bool Boolean;
    } m_Value;

    enum class Type: RF_Type::UInt8
    {
        Integer,
        Float,
        String,
        Boolean
    } m_Type;
};

}

#endif // ZP_VARIANT_HPP
