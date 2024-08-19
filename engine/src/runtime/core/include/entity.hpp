/*
    ʵ�壺����������壬��һ��Mesh������������һ������EntityPart
*/
#pragma once

#include "abstract_object.hpp"
#include "mesh.hpp"
#include "entity_part.hpp"

namespace PrimalDawn{
    enum ENTITY_TYPE {
        PRIMITIVE_TYPE_CUBE = 1,
        PRIMITIVE_TYPE_SPHERE,
    };
    class Entity : public AbstractObject {
    public:
        typedef std::vector<EntityPart*> EntityPartList;
    private:
        // ʵ�����������
        std::unique_ptr<Mesh> mMesh;
        // ʵ�岿�����б�
        EntityPartList mEntityPartList;
        // ʵ���޷�ֱ�ӹ���
        Entity();
    public:
        ~Entity();
    };
}