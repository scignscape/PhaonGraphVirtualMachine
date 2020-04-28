
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-instance.h"

#include "graph/dgdb-node.h"
#include "graph/dgdb-frame.h"

#include "types/dgdb-type-builder.h"


#include <typeinfo>
#include <QDebug> 

USING_KANS(DGDB)

DgDb_Instance::DgDb_Instance()
{
 default_frame_ = new DgDb_Frame();
 current_frame_ = default_frame_;
 current_type_builder_ = new DgDb_Type_Builder;
}

void DgDb_Instance::build_default_types()
{
 current_type_builder_->build(&types_by_name_);
}

DgDb_Type* DgDb_Instance::get_type_by_name(QString tn)
{
 return types_by_name_.value(tn);
}

DgDb_Node* DgDb_Instance::_add(void* v, QString tn)
{
 DgDb_Node* result = new DgDb_Node(v);
 current_frame_->add(result);

 qDebug() << "TN is: " << tn;

 return result;
}


