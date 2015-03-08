#ifndef RDB_DCL_DOCUMENT_HPP
#define RDB_DCL_DOCUMENT_HPP

#include <RadonFramework/Radon.hpp>
#include <RadonFramework/Util/UUID.hpp>

namespace RadiumDB { namespace DCL {

class Document
{
public:
    RF_Util::UUID ID()const;
private:
    RF_Util::UUID m_ID;
};

} }

#endif // RDB_DCL_DOCUMENT_HPP
