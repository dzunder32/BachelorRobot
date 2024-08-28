#include "widget3d.h"

Widget3D::Widget3D(QWidget *parent) : QWidget(parent)
{
    _rootEntity = new Qt3DCore::QEntity();
    _view  = new Qt3DExtras::Qt3DWindow();
    _view->setRootEntity(_rootEntity);
    _widget3D = QWidget::createWindowContainer(_view);
    _widget3D->setMinimumSize(QSize(200, 100));
    _widget3D->setMaximumSize(_view->screen()->size());
    _view->defaultFrameGraph()->setClearColor(QColor(50,50,50));
    // Kamera
    _cameraEntity = _view->camera();
    _cameraEntity->lens()->setPerspectiveProjection(50.0f, 16.0f/9.0f, 0.1f, 2000.0f);
    _cameraEntity->setPosition(QVector3D(-1500.0f, 1700.0f, 1500.0f));
    _cameraEntity->setUpVector(QVector3D(0, 0, 1));
    _cameraEntity->setViewCenter(QVector3D(0, 0, 0));
    _cameraEntity->setFarPlane(20000);

    //Licht
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(_cameraEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(0.8);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(_cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    //Auswahl der Kamera

    _camController = new CameraController(_rootEntity);

    //Andere Kameras
    //_camController = new Qt3DExtras::QOrbitCameraController(_rootEntity);
    //_camController = new Qt3DExtras::QFirstPersonCameraController(_rootEntity);

    _camController->setLinearSpeed( -1000.0f );
    _camController->setLookSpeed( -2000.0f );
    _camController->setCamera(_cameraEntity);

    trans_tool     = new Qt3DCore::QTransform();
    trans_polaris  = new Qt3DCore::QTransform();
    trans_position = new Qt3DCore::QTransform();
    trans_point    = new Qt3DCore::QTransform();

    if (trackData)
    {
        livePlot = new LivePlot();
        connect(this,&Widget3D::updatePlt,livePlot,&LivePlot::addPts);
        livePlot->show();
        setDecimalPlaces(3);

        livePlot2 = new LivePlot2();
        connect(this,&Widget3D::updatePlt2,livePlot2,&LivePlot2::addPts);
        livePlot2->show();
        connect(livePlot,&LivePlot::sendConfigName,livePlot2,&LivePlot2::getConfigName);
        connect(livePlot,&LivePlot::sendDataExtract50,livePlot2,&LivePlot2::getDataExtract50);
    }




    ToolVals=QVector <QVector <double>>(meanVal,QVector <double>(7,0));
    PolarisVals=ToolVals;

    // Create a new entity
    Qt3DCore::QEntity *planeToolEntity = new Qt3DCore::QEntity(_rootEntity);
    // Create a sphere mesh and set its radius
    Qt3DExtras::QSphereMesh *sphere = new Qt3DExtras::QSphereMesh();
    sphere->setRadius(10);
    planeToolEntity->addComponent(sphere);

    // Create a material and set its diffuse color
    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(255,0,0));
    planeToolEntity->addComponent(material);
    // Create a transform and set its translation
    planeToolEntity->addComponent(planeToolTransform);

}
Widget3D::~Widget3D(){}

void Widget3D::addObject(Qt3DCore::QEntity *entity,QVector3D pos,QQuaternion quad)
{
    entity->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(_rootEntity));
    auto *trans = new Qt3DCore::QTransform();
    entity->addComponent(trans);
    trans->setTranslation(pos);
    trans->setRotation(quad);
}

void Widget3D::addObject(Qt3DCore::QEntity *entity)
{
    entity->Qt3DCore::QEntity::setParent(static_cast<Qt3DCore::QEntity*>(_rootEntity));
}

QWidget *Widget3D::getQWidget() const
{
    return _widget3D;
}

void Widget3D::setDecimalPlaces(int val)
{
    decimalPlaces = val;
    livePlot->setDecimalPlaces(val);
}

void Widget3D::addTransTool(Qt3DCore::QEntity *entity)
{
    entity->addComponent(trans_tool);

}

void Widget3D::addPlane(Plane *plane)
{
   _plane = plane;
}

void Widget3D::addTransPolaris(Qt3DCore::QEntity *entity)
{
    entity->addComponent(trans_polaris);
    trans_polaris->setTranslation(QVector3D(200,-200,200));
}

void Widget3D::setPosMatrix(Qt3DCore::QTransform *pos)
{
    trans_position = pos;
}


void Widget3D::getToolData(QVector <double> data)
{
    ToolMatrix = DataMatrix(ToolVals,data);
    QMatrix4x4 temp_T_plane =  trans_polaris->matrix()*ToolMatrix;

    //check weather the matrix has changed
//    float sum_T;
    QMatrix4x4 subtaction_T = temp_T_plane - T_plane;

    for (int i=0;i<4;i++){
        for (int k=0;k<4;k++){
            sum_T += abs(subtaction_T(i,k));
        }
    }

    if(sum_T>1)
    {

        T_plane = temp_T_plane;
        _plane->setMatrix(T_plane);
        planeToolTransform->setTranslation(_plane->translation());
        _plane->setTranslation(_plane->translation() + _plane->matrix().column(0).toVector3D() * _plane->xLimit/2);
        emit updatePlane();
    }
    sum_T=0;
    //
    if(updateCounter == 30){updateCounter=0;emit updatePlane();}
    updateCounter++;

}

void Widget3D::getPolarisData(QVector <double> data)
{
    //    float pitch,yaw,roll;
    //    QQuaternion(data[0],data[1],data[2],data[3]).getEulerAngles(&pitch,&yaw,&roll);
    //    emit updatePlt({roundDecimalPlaces(pitch),roundDecimalPlaces(yaw),roundDecimalPlaces(roll)});
    //    emit updatePlt2({data[4],data[5],data[6]});
    PolarisMatrix = DataMatrix(PolarisVals,data);
    trans_polaris->setMatrix(trans_position->matrix()*PolarisMatrix.inverted());
}


QVector <double> Widget3D::meanVector(QVector <QVector <double>> &vec,QVector <double> data)
{
    int ind;
    QVector <double> mVec(data.size(),0);
    vec.prepend(data);
    vec.removeLast();

    for (auto i:vec)
    {
        ind=0;
        for (auto j:i)
        {
            mVec[ind] = mVec[ind]+j;
            ind++;
        }
    }
    for (auto &i:mVec)
    {
        i = i/vec.size();
    }
    return mVec;
}
QMatrix4x4 Widget3D::DataMatrix(QVector <QVector <double>> &vals,QVector <double> data)
{
    QMatrix4x4 mat;
    QVector <double> meanData;
    meanData = meanVector(vals,data);
//    mat.rotate(QQuaternion::fromEulerAngles())
    mat.rotate(QQuaternion(meanData[0],meanData[1],meanData[2],meanData[3]));
    mat.setColumn(3,QVector4D(meanData[4],meanData[5],meanData[6],1));
    return mat;
}

double Widget3D::roundDecimalPlaces(double val)
{
    double multi = qPow(10,decimalPlaces);
    return qRound(val*multi)/multi;
}

void Widget3D::setFileName(QString name)
{
    livePlot->setConfigName(name);
    livePlot2->setConfigName(name);
}

void Widget3D::setViewCenter(QVector3D point)
{
    _cameraEntity->setViewCenter(point);
}

void Widget3D::drawPoint(QVector3D position, float size, QColor color)
{
    // Create a new entity
    Qt3DCore::QEntity *entity = new Qt3DCore::QEntity(_rootEntity);
    pointEntities.append(entity);
    // Create a sphere mesh and set its radius
    Qt3DExtras::QSphereMesh *sphere = new Qt3DExtras::QSphereMesh();
    sphere->setRadius(size);
    entity->addComponent(sphere);

    // Create a material and set its diffuse color
    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(color);
    entity->addComponent(material);

    // Create a transform and set its translation
    Qt3DCore::QTransform *transform = new Qt3DCore::QTransform();
    transform->setTranslation(position);
    entity->addComponent(transform);

}



void Widget3D::addCylinderBetweenPoints(const QVector3D& startPoint, const QVector3D& endPoint)
{
    Qt3DCore::QEntity *cylinderEntity = new Qt3DCore::QEntity(_rootEntity);
    lineEntities.append(cylinderEntity);
    // Create the cylinder mesh
    auto cylinder = new Qt3DExtras::QCylinderMesh(cylinderEntity);

    cylinder->setLength(endPoint.distanceToPoint(startPoint)); // Set the length based on the distance between the points
    cylinder->setRadius(1.0f); // Set the radius of the cylinder

    // Calculate the midpoint and rotation angles
    auto midPoint = (startPoint + endPoint) / 2;
    auto transPoint = endPoint - startPoint;
    // auto xAngle = atan(sqrt(pow(transPoint.z(), 2) + pow(transPoint.x(), 2)) / transPoint.y()) / M_PI * 180;
    auto xAngle = atan2(sqrt(pow(transPoint.z(), 2) + pow(transPoint.x(), 2)) , transPoint.y()) / M_PI * 180;

    // auto yAngle = (transPoint.x() == 0 && transPoint.z() == 0)? 0 : atan(transPoint.x() / transPoint.z()) / M_PI * 180;
    auto yAngle = (transPoint.x() == 0 && transPoint.z() == 0)? 0 : atan2(transPoint.x(), transPoint.z()) / M_PI * 180;

    // Create and configure the transformation node
    auto transform = new Qt3DCore::QTransform(cylinderEntity);
    transform->setRotationX(xAngle);
    transform->setRotationY(yAngle);
    transform->setTranslation(midPoint);

    // Add material to the cylinder
    auto material = new Qt3DExtras::QPhongMaterial(cylinderEntity);
    material->setDiffuse("#ffff00"); // Set the color of the cylinder

    // Add components to the entity
    cylinderEntity->addComponent(cylinder);
    cylinderEntity->addComponent(transform);
    cylinderEntity->addComponent(material);
}


void Widget3D::deleteAllPoints()
{
    for (Qt3DCore::QEntity* entity : pointEntities) {
        delete entity;
    }
    pointEntities.clear();

}
void Widget3D::deleteAllLines()
{
//    qDebug()<<"Here!";
    for (Qt3DCore::QEntity* entity : lineEntities) {
        delete entity;
    }
    lineEntities.clear();
//    qDebug()<<"its aight!";
}

