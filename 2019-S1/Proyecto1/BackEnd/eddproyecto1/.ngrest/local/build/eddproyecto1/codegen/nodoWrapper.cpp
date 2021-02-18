// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest
// DO NOT EDIT. ANY CHANGES WILL BE LOST

#include <ngrest/utils/Log.h>
#include <ngrest/utils/fromcstring.h>
#include <ngrest/utils/tostring.h>
#include <ngrest/utils/Exception.h>
#include <ngrest/common/ObjectModel.h>
#include <ngrest/common/ObjectModelUtils.h>
#include <ngrest/common/Message.h>
#include "nodoWrapper.h"



// struct Catedratico

void ::CatedraticoSerializer::serialize(::ngrest::MessageContext* context, const Catedratico& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* codigoNode = context->pool->alloc< ::ngrest::NamedNode>("codigo");
    static_cast< ::ngrest::Object*>(node)->firstChild = codigoNode;
// SERIALIZE : std::string string
    codigoNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.codigo.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* nombreNode = context->pool->alloc< ::ngrest::NamedNode>("nombre");
    codigoNode->nextSibling = nombreNode;
// SERIALIZE : std::string string
    nombreNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.nombre.c_str());
// END SERIALIZE: std::string string
    nombreNode->nextSibling = oldFirstChildNode;
}

void ::CatedraticoSerializer::deserialize(const ::ngrest::Node* node, Catedratico& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Catedratico");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "codigo", value.codigo);
    ::ngrest::ObjectModelUtils::getChildValue(object, "nombre", value.nombre);
}




// struct Curso

void ::CursoSerializer::serialize(::ngrest::MessageContext* context, const Curso& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* codigoNode = context->pool->alloc< ::ngrest::NamedNode>("codigo");
    static_cast< ::ngrest::Object*>(node)->firstChild = codigoNode;
// SERIALIZE : std::string string
    codigoNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.codigo.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* nombreNode = context->pool->alloc< ::ngrest::NamedNode>("nombre");
    codigoNode->nextSibling = nombreNode;
// SERIALIZE : std::string string
    nombreNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.nombre.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* catedraticoNode = context->pool->alloc< ::ngrest::NamedNode>("catedratico");
    nombreNode->nextSibling = catedraticoNode;
// SERIALIZE : std::string string
    catedraticoNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.catedratico.c_str());
// END SERIALIZE: std::string string
    catedraticoNode->nextSibling = oldFirstChildNode;
}

void ::CursoSerializer::deserialize(const ::ngrest::Node* node, Curso& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Curso");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "codigo", value.codigo);
    ::ngrest::ObjectModelUtils::getChildValue(object, "nombre", value.nombre);
    ::ngrest::ObjectModelUtils::getChildValue(object, "catedratico", value.catedratico);
}




// struct Salon

void ::SalonSerializer::serialize(::ngrest::MessageContext* context, const Salon& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* edificioNode = context->pool->alloc< ::ngrest::NamedNode>("edificio");
    static_cast< ::ngrest::Object*>(node)->firstChild = edificioNode;
// SERIALIZE : std::string string
    edificioNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.edificio.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* salonNode = context->pool->alloc< ::ngrest::NamedNode>("salon");
    edificioNode->nextSibling = salonNode;
// SERIALIZE : std::string string
    salonNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.salon.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* capacidadNode = context->pool->alloc< ::ngrest::NamedNode>("capacidad");
    salonNode->nextSibling = capacidadNode;
// SERIALIZE : std::string string
    capacidadNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.capacidad.c_str());
// END SERIALIZE: std::string string
    capacidadNode->nextSibling = oldFirstChildNode;
}

void ::SalonSerializer::deserialize(const ::ngrest::Node* node, Salon& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Salon");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "edificio", value.edificio);
    ::ngrest::ObjectModelUtils::getChildValue(object, "salon", value.salon);
    ::ngrest::ObjectModelUtils::getChildValue(object, "capacidad", value.capacidad);
}




// struct Hora

void ::HoraSerializer::serialize(::ngrest::MessageContext* context, const Hora& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* horaInicioNode = context->pool->alloc< ::ngrest::NamedNode>("horaInicio");
    static_cast< ::ngrest::Object*>(node)->firstChild = horaInicioNode;
// SERIALIZE : std::string string
    horaInicioNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.horaInicio.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* horaFinalNode = context->pool->alloc< ::ngrest::NamedNode>("horaFinal");
    horaInicioNode->nextSibling = horaFinalNode;
// SERIALIZE : std::string string
    horaFinalNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.horaFinal.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* diaNode = context->pool->alloc< ::ngrest::NamedNode>("dia");
    horaFinalNode->nextSibling = diaNode;
// SERIALIZE : std::string string
    diaNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.dia.c_str());
// END SERIALIZE: std::string string
    diaNode->nextSibling = oldFirstChildNode;
}

void ::HoraSerializer::deserialize(const ::ngrest::Node* node, Hora& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Hora");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "horaInicio", value.horaInicio);
    ::ngrest::ObjectModelUtils::getChildValue(object, "horaFinal", value.horaFinal);
    ::ngrest::ObjectModelUtils::getChildValue(object, "dia", value.dia);
}




// struct Matriz

void ::MatrizSerializer::serialize(::ngrest::MessageContext* context, const Matriz& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* nombreDiaNode = context->pool->alloc< ::ngrest::NamedNode>("nombreDia");
    static_cast< ::ngrest::Object*>(node)->firstChild = nombreDiaNode;
// SERIALIZE : std::string string
    nombreDiaNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.nombreDia.c_str());
// END SERIALIZE: std::string string
    nombreDiaNode->nextSibling = oldFirstChildNode;
}

void ::MatrizSerializer::deserialize(const ::ngrest::Node* node, Matriz& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Matriz");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "nombreDia", value.nombreDia);
}




// struct Dia

void ::DiaSerializer::serialize(::ngrest::MessageContext* context, const Dia& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* nombreDiaNode = context->pool->alloc< ::ngrest::NamedNode>("nombreDia");
    static_cast< ::ngrest::Object*>(node)->firstChild = nombreDiaNode;
// SERIALIZE : std::string string
    nombreDiaNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.nombreDia.c_str());
// END SERIALIZE: std::string string
    nombreDiaNode->nextSibling = oldFirstChildNode;
}

void ::DiaSerializer::deserialize(const ::ngrest::Node* node, Dia& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Dia");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "nombreDia", value.nombreDia);
}




// struct Asignacion

void ::AsignacionSerializer::serialize(::ngrest::MessageContext* context, const Asignacion& value, ::ngrest::Node* node)
{
    ::ngrest::NamedNode* oldFirstChildNode = static_cast< ::ngrest::Object*>(node)->firstChild;
    ::ngrest::NamedNode* diaNode = context->pool->alloc< ::ngrest::NamedNode>("dia");
    static_cast< ::ngrest::Object*>(node)->firstChild = diaNode;
// SERIALIZE : std::string string
    diaNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.dia.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* cod_cursoNode = context->pool->alloc< ::ngrest::NamedNode>("cod_curso");
    diaNode->nextSibling = cod_cursoNode;
// SERIALIZE : std::string string
    cod_cursoNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.cod_curso.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* cod_catedraticoNode = context->pool->alloc< ::ngrest::NamedNode>("cod_catedratico");
    cod_cursoNode->nextSibling = cod_catedraticoNode;
// SERIALIZE : std::string string
    cod_catedraticoNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.cod_catedratico.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* horaInicioNode = context->pool->alloc< ::ngrest::NamedNode>("horaInicio");
    cod_catedraticoNode->nextSibling = horaInicioNode;
// SERIALIZE : std::string string
    horaInicioNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.horaInicio.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* horaFinalNode = context->pool->alloc< ::ngrest::NamedNode>("horaFinal");
    horaInicioNode->nextSibling = horaFinalNode;
// SERIALIZE : std::string string
    horaFinalNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.horaFinal.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* edificioNode = context->pool->alloc< ::ngrest::NamedNode>("edificio");
    horaFinalNode->nextSibling = edificioNode;
// SERIALIZE : std::string string
    edificioNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.edificio.c_str());
// END SERIALIZE: std::string string
    ::ngrest::NamedNode* salonNode = context->pool->alloc< ::ngrest::NamedNode>("salon");
    edificioNode->nextSibling = salonNode;
// SERIALIZE : std::string string
    salonNode->node = context->pool->alloc< ::ngrest::Value>(::ngrest::ValueType::String, value.salon.c_str());
// END SERIALIZE: std::string string
    salonNode->nextSibling = oldFirstChildNode;
}

void ::AsignacionSerializer::deserialize(const ::ngrest::Node* node, Asignacion& value)
{
    NGREST_ASSERT(node->type == ::ngrest::NodeType::Object, "Unexpected node type while deserializing ::Asignacion");
    const ::ngrest::Object* object = static_cast<const ::ngrest::Object*>(node);
    ::ngrest::ObjectModelUtils::getChildValue(object, "dia", value.dia);
    ::ngrest::ObjectModelUtils::getChildValue(object, "cod_curso", value.cod_curso);
    ::ngrest::ObjectModelUtils::getChildValue(object, "cod_catedratico", value.cod_catedratico);
    ::ngrest::ObjectModelUtils::getChildValue(object, "horaInicio", value.horaInicio);
    ::ngrest::ObjectModelUtils::getChildValue(object, "horaFinal", value.horaFinal);
    ::ngrest::ObjectModelUtils::getChildValue(object, "edificio", value.edificio);
    ::ngrest::ObjectModelUtils::getChildValue(object, "salon", value.salon);
}





