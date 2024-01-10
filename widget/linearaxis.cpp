#include "linearaxisrv6sl.h"

LinearAxisRV6SL::LinearAxisRV6SL(Qt3DCore::QEntity* parent)
{
    this->Qt3DCore::QEntity::setParent(parent);
    this->addComponent(static_cast<Qt3DCore::QTransform*>(this));
    _substructure=new STLMesh(this);
    _substructure->setRotationX(-90);
    _substructure->setTranslation(QVector3D(-188,0,50));
    _substructure->setSource("UnterbauRV-6SL.STL");
    _substructure->Qt3DCore::QEntity::setEnabled(true);
    //Linearachse
    _axis  =new STLMesh(_substructure);
    _axis->setRotationX(90);
    _axis->setTranslation(QVector3D(911,1829,572));
    _axis->setSource("Linearachse.STL");
    _axis->Qt3DCore::QEntity::setEnabled(true);
    //Einfügen eiener Umgebung um zu verschieben
    auto* tempEnt1 =new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(_axis));
    auto* tempTrans1 =new Qt3DCore::QTransform();
    tempTrans1->setTranslation(QVector3D(0,0,0));
    tempEnt1->addComponent(tempTrans1);
    //Schlitten
    _sled  =new STLMesh(tempEnt1);
    _sled->setTranslation(QVector3D(0,0,-70.11));
    _sled->setSource("Schlitten.STL");
    _sled->Qt3DCore::QEntity::setEnabled(true);
    //Einfügen eiener Umgebung um zu verschieben
    auto* tempEnt2 =new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(_sled));
    auto* tempTrans2 =new Qt3DCore::QTransform();
    tempTrans2->setTranslation(QVector3D(0,144,70.11));
    tempEnt2->addComponent(tempTrans2);
    Joint7=tempTrans1;
    Sled=tempEnt2;

}

