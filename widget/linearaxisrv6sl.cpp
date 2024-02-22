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

    sled_pos_inBase();

    Joint7=tempTrans1;
    Sled=tempEnt2;

}

void LinearAxisRV6SL::showAxes(Qt3DCore::QEntity *Ent1, Qt3DCore::QEntity *Ent2)
{
    //Coordinaten System des Unterbaus
    substructure_CSystem = new CoordinateSystem(_substructure);
    substructure_CSystem->setLength(500);
    substructure_CSystem->setNegativeAxis(false);

    axis_CSystem = new CoordinateSystem(Ent1);
    axis_CSystem->setLength(500);
    axis_CSystem->setNegativeAxis(false);

    sled_CSystem = new CoordinateSystem(Ent2);
    sled_CSystem->setLength(500);
    sled_CSystem->setNegativeAxis(false);
}

void LinearAxisRV6SL::sled_pos_inBase(){

    auto* tempEnt3 =new Qt3DCore::QEntity(static_cast<Qt3DCore::QEntity*>(this));
    auto* tempTrans3 =new Qt3DCore::QTransform();
    tempEnt3->addComponent(tempTrans3);
    QMatrix3x3 rotationMatrix =_substructure->rotation().toRotationMatrix(); // Your rotation matrix
    //    QVector3D vector=_sled->translation() + tempTrans2->translation() + _axis->translation();
    QVector3D sled_vector= _axis->translation();

    sled_position = rotate_vector(sled_vector,rotationMatrix) +_substructure->translation() + QVector3D(0,144,0);
    qDebug()<<sled_position;
    // tempTrans3->setTranslation(sled_position);
    // CoordinateSystem *CSystem = new CoordinateSystem(tempEnt3);
    // CSystem->setLength(500);
    // CSystem->setNegativeAxis(false);

}

QVector3D LinearAxisRV6SL::rotate_vector(QVector3D vector,QMatrix3x3 rotationMatrix)
{
    QVector4D vector4D = QVector4D(vector, 1.0);
    QVector4D result4D = QMatrix4x4(rotationMatrix) * vector4D;
    QVector3D result = result4D.toVector3D();

    return result;

}
void LinearAxisRV6SL::set_sled_position(QMatrix3x3 rotationMatrix)
{
    sled_position=rotate_vector(sled_position, rotationMatrix);
    qDebug()<<sled_position;
}
