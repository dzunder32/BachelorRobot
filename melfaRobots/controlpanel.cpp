#include "controlpanel.h"
#include "ui_controlpanel.h"
#include "QStyleFactory"

ControlPanel::ControlPanel(Kinematik* robot,QWidget *parent) :
    SubWindow(parent),
    ui(new Ui::ControlPanel)
{

    _robot=robot;
    ui->setupUi(this);
    // Set Slider, Spinboxes
    connect(robot,&Kinematik::xChanged,ui->sb_x,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::yChanged,ui->sb_y,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::zChanged,ui->sb_z,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::aChanged,ui->sb_a,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::bChanged,ui->sb_b,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::cChanged,ui->sb_c,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::l1Changed,ui->sb_l1,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::flg1Changed,ui->cb_Flg1,&QComboBox::setCurrentIndex);
    connect(robot,&Kinematik::flg2Changed,ui->spinBox_Flg2,&QSpinBox::setValue);

    connect(robot,&Kinematik::j1Changed,ui->sb_j1,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::j2Changed,ui->sb_j2,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::j3Changed,ui->sb_j3,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::j4Changed,ui->sb_j4,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::j5Changed,ui->sb_j5,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::j6Changed,ui->sb_j6,&QDoubleSpinBox::setValue);
    connect(robot,&Kinematik::j7Changed,ui->sb_j7,&QDoubleSpinBox::setValue);

    connect(robot,&Kinematik::xChanged,ui->Slider_BaseX,&QSlider::setValue);
    connect(robot,&Kinematik::yChanged,ui->Slider_BaseY,&QSlider::setValue);
    connect(robot,&Kinematik::zChanged,ui->Slider_BaseZ,&QSlider::setValue);
    connect(robot,&Kinematik::cChanged,ui->Slider_BaseC,&QSlider::setValue);
    connect(robot,&Kinematik::l1Changed,ui->Slider_BaseL1,&QSlider::setValue);

    connect(robot,&Kinematik::j1Changed,ui->SliderJ1,&QSlider::setValue);
    connect(robot,&Kinematik::j2Changed,ui->SliderJ2,&QSlider::setValue);
    connect(robot,&Kinematik::j3Changed,ui->SliderJ3,&QSlider::setValue);
    connect(robot,&Kinematik::j4Changed,ui->SliderJ4,&QSlider::setValue);
    connect(robot,&Kinematik::j5Changed,ui->SliderJ5,&QSlider::setValue);
    connect(robot,&Kinematik::j6Changed,ui->SliderJ6,&QSlider::setValue);
    connect(robot,&Kinematik::j7Changed,ui->SliderJ7,&QSlider::setValue);

    connect(_robot,&Kinematik::jointsChanged,this,&ControlPanel::_setJoints);
    connect(_robot,&Kinematik::kartChanged,this,&ControlPanel::_setKart);

    //Spinboxes change
    connect(ui->sb_x,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_x->hasFocus()){_setX(d);}});
    connect(ui->sb_y,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_y->hasFocus()){_setY(d);}});
    connect(ui->sb_z,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_z->hasFocus()){_setZ(d);}});
    connect(ui->sb_a,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_a->hasFocus()){_setA(d);}});
    connect(ui->sb_b,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_b->hasFocus()){_setB(d);}});
    connect(ui->sb_c,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_c->hasFocus()){_setC(d);}});
    connect(ui->sb_l1, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_l1->hasFocus()){_setL1(d);}});
    connect(ui->cb_Flg1, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int d){ if(ui->cb_Flg1->hasFocus()){_setFlg1(d);}});

    connect(ui->sb_j1, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j1->hasFocus()){_setJ1(d);}});
    connect(ui->sb_j2, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j2->hasFocus()){_setJ2(d);}});
    connect(ui->sb_j3, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j3->hasFocus()){_setJ3(d);}});
    connect(ui->sb_j4, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j4->hasFocus()){_setJ4(d);}});
    connect(ui->sb_j5, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j5->hasFocus()){_setJ5(d);}});
    connect(ui->sb_j6, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j6->hasFocus()){_setJ6(d);}});
    connect(ui->sb_j7, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double d){ if(ui->sb_j7->hasFocus()){_setJ7(d);}});

    //Joint movement
    connect(ui->SliderJ1, &QSlider::sliderMoved, this, &ControlPanel::_setJ1);
    connect(ui->SliderJ2, &QSlider::sliderMoved, this, &ControlPanel::_setJ2);
    connect(ui->SliderJ3, &QSlider::sliderMoved, this, &ControlPanel::_setJ3);
    connect(ui->SliderJ4, &QSlider::sliderMoved, this, &ControlPanel::_setJ4);
    connect(ui->SliderJ5, &QSlider::sliderMoved, this, &ControlPanel::_setJ5);
    connect(ui->SliderJ6, &QSlider::sliderMoved, this, &ControlPanel::_setJ6);
    connect(ui->SliderJ7, &QSlider::sliderMoved, this, &ControlPanel::_setJ7);

    connect(ui->PB_J1_plus, &QPushButton::clicked, [=]{this->_setJ1(robot->j1()+ui->SB_Increment->value());});
    connect(ui->PB_J2_plus, &QPushButton::clicked, [=]{this->_setJ2(robot->j2()+ui->SB_Increment->value());});
    connect(ui->PB_J3_plus, &QPushButton::clicked, [=]{this->_setJ3(robot->j3()+ui->SB_Increment->value());});
    connect(ui->PB_J4_plus, &QPushButton::clicked, [=]{this->_setJ4(robot->j4()+ui->SB_Increment->value());});
    connect(ui->PB_J5_plus, &QPushButton::clicked, [=]{this->_setJ5(robot->j5()+ui->SB_Increment->value());});
    connect(ui->PB_J6_plus, &QPushButton::clicked, [=]{this->_setJ6(robot->j6()+ui->SB_Increment->value());});
    connect(ui->PB_J7_plus, &QPushButton::clicked, [=]{this->_setJ7(robot->j7()+ui->SB_Increment->value());});

    connect(ui->PB_J1_minus, &QPushButton::clicked, [=]{this->_setJ1(robot->j1()-ui->SB_Increment->value());});
    connect(ui->PB_J2_minus, &QPushButton::clicked, [=]{this->_setJ2(robot->j2()-ui->SB_Increment->value());});
    connect(ui->PB_J3_minus, &QPushButton::clicked, [=]{this->_setJ3(robot->j3()-ui->SB_Increment->value());});
    connect(ui->PB_J4_minus, &QPushButton::clicked, [=]{this->_setJ4(robot->j4()-ui->SB_Increment->value());});
    connect(ui->PB_J5_minus, &QPushButton::clicked, [=]{this->_setJ5(robot->j5()-ui->SB_Increment->value());});
    connect(ui->PB_J6_minus, &QPushButton::clicked, [=]{this->_setJ6(robot->j6()-ui->SB_Increment->value());});
    connect(ui->PB_J7_minus, &QPushButton::clicked, [=]{this->_setJ7(robot->j7()-ui->SB_Increment->value());});

    //Base movement
    connect(ui->Slider_BaseX, &QSlider::sliderMoved, this, &ControlPanel::_setX);
    connect(ui->Slider_BaseY, &QSlider::sliderMoved, this, &ControlPanel::_setY);
    connect(ui->Slider_BaseZ, &QSlider::sliderMoved, this, &ControlPanel::_setZ);
    connect(ui->Slider_BaseC, &QSlider::sliderMoved, this, &ControlPanel::_setC);
    connect(ui->Slider_BaseL1,&QSlider::sliderMoved, this, &ControlPanel::_setL1);

    connect(ui->PB_BaseX_plus, &QPushButton::clicked, [=]{this->_setX(robot->x()+ui->SB_Increment->value());});
    connect(ui->PB_BaseY_plus, &QPushButton::clicked, [=]{this->_setY(robot->y()+ui->SB_Increment->value());});
    connect(ui->PB_BaseZ_plus, &QPushButton::clicked, [=]{this->_setZ(robot->z()+ui->SB_Increment->value());});
    connect(ui->PB_BaseA_plus, &QPushButton::clicked, [=]{this->_setA(robot->a()+ui->SB_Increment->value());});
    connect(ui->PB_BaseB_plus, &QPushButton::clicked, [=]{this->_setB(robot->b()+ui->SB_Increment->value());});
    connect(ui->PB_BaseC_plus, &QPushButton::clicked, [=]{this->_setC(robot->c()+ui->SB_Increment->value());});
    connect(ui->PB_BaseL1_plus, &QPushButton::clicked, [=]{this->_setL1(robot->l1()+ui->SB_Increment->value());});

    connect(ui->PB_BaseX_minus, &QPushButton::clicked, [=]{this->_setX(robot->x()-ui->SB_Increment->value());});
    connect(ui->PB_BaseY_minus, &QPushButton::clicked, [=]{this->_setY(robot->y()-ui->SB_Increment->value());});
    connect(ui->PB_BaseZ_minus, &QPushButton::clicked, [=]{this->_setZ(robot->z()-ui->SB_Increment->value());});
    connect(ui->PB_BaseA_minus, &QPushButton::clicked, [=]{this->_setA(robot->a()-ui->SB_Increment->value());});
    connect(ui->PB_BaseB_minus, &QPushButton::clicked, [=]{this->_setB(robot->b()-ui->SB_Increment->value());});
    connect(ui->PB_BaseC_minus, &QPushButton::clicked, [=]{this->_setC(robot->c()-ui->SB_Increment->value());});
    connect(ui->PB_BaseL1_minus,&QPushButton::clicked, [=]{this->_setL1(robot->l1()-ui->SB_Increment->value());});

    //Tool Movement
    connect(ui->PB_ToolX_plus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::X,ui->SB_Increment->value());});
    connect(ui->PB_ToolY_plus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::Y,ui->SB_Increment->value());});
    connect(ui->PB_ToolZ_plus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::Z,ui->SB_Increment->value());});
    connect(ui->PB_ToolA_plus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::A,ui->SB_Increment->value());});
    connect(ui->PB_ToolB_plus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::B,ui->SB_Increment->value());});
    connect(ui->PB_ToolC_plus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::C,ui->SB_Increment->value());});

    connect(ui->PB_ToolX_minus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::X,-ui->SB_Increment->value());});
    connect(ui->PB_ToolY_minus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::Y,-ui->SB_Increment->value());});
    connect(ui->PB_ToolZ_minus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::Z,-ui->SB_Increment->value());});
    connect(ui->PB_ToolA_minus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::A,-ui->SB_Increment->value());});
    connect(ui->PB_ToolB_minus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::B,-ui->SB_Increment->value());});
    connect(ui->PB_ToolC_minus, &QPushButton::clicked, [=]{_robot->ToolMovement(Transformations::C,-ui->SB_Increment->value());});

    //Home
    connect(ui->PB_Phome, &QPushButton::clicked,this,&ControlPanel::_home);

    //Limits
    ui->sb_j1->setRange(_robot->getJ1Min(),_robot->getJ1Max());
    ui->sb_j2->setRange(_robot->getJ2Min(),_robot->getJ2Max());
    ui->sb_j3->setRange(_robot->getJ3Min(),_robot->getJ3Max());
    ui->sb_j4->setRange(_robot->getJ4Min(),_robot->getJ4Max());
    ui->sb_j5->setRange(_robot->getJ5Min(),_robot->getJ5Max());
    ui->sb_j6->setRange(_robot->getJ6Min(),_robot->getJ6Max());

    ui->SliderJ1->setRange(_robot->getJ1Min(),_robot->getJ1Max());
    ui->SliderJ2->setRange(_robot->getJ2Min(),_robot->getJ2Max());
    ui->SliderJ3->setRange(_robot->getJ3Min(),_robot->getJ3Max());
    ui->SliderJ4->setRange(_robot->getJ4Min(),_robot->getJ4Max());
    ui->SliderJ5->setRange(_robot->getJ5Min(),_robot->getJ5Max());
    ui->SliderJ6->setRange(_robot->getJ6Min(),_robot->getJ6Max());

    //Updating
    connect(ui->SliderJ1, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);
    connect(ui->SliderJ2, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);
    connect(ui->SliderJ3, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);
    connect(ui->SliderJ4, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);
    connect(ui->SliderJ5, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);
    connect(ui->SliderJ6, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);
    connect(ui->SliderJ7, &QSlider::sliderReleased, this, &ControlPanel::_updateRobot);

    connect(ui->sb_x, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_y, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_z, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_a, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_b, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_c, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_l1, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);

    connect(ui->sb_j1, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_j2, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_j3, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_j4, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_j5, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_j6, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);
    connect(ui->sb_j7, &QDoubleSpinBox::editingFinished, this, &ControlPanel::_updateRobot);

    connect(ui->PB_ToolX_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolY_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolZ_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolA_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolB_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolC_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);

    connect(ui->PB_ToolX_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolY_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolZ_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolA_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolB_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_ToolC_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);

    connect(ui->PB_BaseX_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseY_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseZ_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseA_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseB_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseC_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseL1_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);

    connect(ui->PB_BaseX_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseY_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseZ_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseA_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseB_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseC_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_BaseL1_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);

    connect(ui->PB_J1_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J2_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J3_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J4_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J5_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J6_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J7_plus, &QPushButton::released, this, &ControlPanel::_updateRobot);

    connect(ui->PB_J1_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J2_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J3_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J4_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J5_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J6_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);
    connect(ui->PB_J7_minus, &QPushButton::released, this, &ControlPanel::_updateRobot);

    //Next Tab:Mov2Point
    RotatedPoint= new CoordinateSystem();
    RotatedPoint->setLength(100);
//    connect(ui->Invers_pushButton,&QPushButton::clicked,[=]{RotatedPoint->setTranslation(
//    QVector3D(ui->lineEdit_X->text().toFloat(),ui->lineEdit_Y->text().toFloat(),ui->lineEdit_Z->text().toFloat()));});
    connect(ui->Invers_pushButton,&QPushButton::clicked,this,&ControlPanel::setTransRotCoord);
}

void ControlPanel::_updateRobot()
{
    if(!_buttonDown())
        _robot->updateRobotFromUi();
}

bool ControlPanel::_buttonDown()
{
    return  ui->PB_J1_plus->isDown() |
            ui->PB_J2_plus->isDown() |
            ui->PB_J3_plus->isDown() |
            ui->PB_J4_plus->isDown() |
            ui->PB_J5_plus->isDown() |
            ui->PB_J6_plus->isDown() |
            ui->PB_J7_plus->isDown() |

            ui->PB_J1_minus->isDown() |
            ui->PB_J2_minus->isDown() |
            ui->PB_J3_minus->isDown() |
            ui->PB_J4_minus->isDown() |
            ui->PB_J5_minus->isDown() |
            ui->PB_J6_minus->isDown() |
            ui->PB_J7_minus->isDown() |

            ui->PB_BaseX_plus->isDown() |
            ui->PB_BaseY_plus->isDown() |
            ui->PB_BaseZ_plus->isDown() |
            ui->PB_BaseA_plus->isDown() |
            ui->PB_BaseB_plus->isDown() |
            ui->PB_BaseC_plus->isDown() |
            ui->PB_BaseL1_plus->isDown() |

            ui->PB_BaseX_minus->isDown() |
            ui->PB_BaseY_minus->isDown() |
            ui->PB_BaseZ_minus->isDown() |
            ui->PB_BaseA_minus->isDown() |
            ui->PB_BaseB_minus->isDown() |
            ui->PB_BaseC_minus->isDown() |
            ui->PB_BaseL1_minus->isDown()|

            ui->PB_ToolX_plus->isDown() |
            ui->PB_ToolY_plus->isDown() |
            ui->PB_ToolZ_plus->isDown() |
            ui->PB_ToolA_plus->isDown() |
            ui->PB_ToolB_plus->isDown() |
            ui->PB_ToolC_plus->isDown() |

            ui->PB_ToolX_minus->isDown() |
            ui->PB_ToolY_minus->isDown() |
            ui->PB_ToolZ_minus->isDown() |
            ui->PB_ToolA_minus->isDown() |
            ui->PB_ToolB_minus->isDown() |
            ui->PB_ToolC_minus->isDown() ;
}

ControlPanel::~ControlPanel()
{
    delete ui;
}


void ControlPanel::_setJ1(double j1){_robot->setJ1(j1);}
void ControlPanel::_setJ2(double j2){_robot->setJ2(j2);}
void ControlPanel::_setJ3(double j3){_robot->setJ3(j3);}
void ControlPanel::_setJ4(double j4){_robot->setJ4(j4);}
void ControlPanel::_setJ5(double j5){_robot->setJ5(j5);}
void ControlPanel::_setJ6(double j6){_robot->setJ6(j6);}
void ControlPanel::_setJ7(double j7){_robot->setJ7(j7);}

void ControlPanel::_setX(double x){_robot->setX(x);}
void ControlPanel::_setY(double y){_robot->setY(y);}
void ControlPanel::_setZ(double z){_robot->setZ(z);}
void ControlPanel::_setA(double a){_robot->setA(a);}
void ControlPanel::_setB(double b){_robot->setB(b);}
void ControlPanel::_setC(double c){_robot->setC(c);}
void ControlPanel::_setL1(double l1){_robot->setL1(l1);}
void ControlPanel::_setFlg1(unsigned int flg1){_robot->setFlg1(flg1);}

void ControlPanel::_home(){
    _robot->setJoints(0,0,90,0,90,0,0);
}

void ControlPanel::_setJoints()
{
    ui->SliderJ1->setValue(_robot->j1());ui->sb_j1->setValue(_robot->j1());
    ui->SliderJ2->setValue(_robot->j2());ui->sb_j2->setValue(_robot->j2());
    ui->SliderJ3->setValue(_robot->j3());ui->sb_j3->setValue(_robot->j3());
    ui->SliderJ4->setValue(_robot->j4());ui->sb_j4->setValue(_robot->j4());
    ui->SliderJ5->setValue(_robot->j5());ui->sb_j5->setValue(_robot->j5());
    ui->SliderJ6->setValue(_robot->j6());ui->sb_j6->setValue(_robot->j6());
    ui->SliderJ7->setValue(_robot->j7());ui->sb_j7->setValue(_robot->j7());
}

void ControlPanel::_setKart()
{
    ui->Slider_BaseX->setValue(_robot->x());ui->sb_x->setValue(_robot->x());
    ui->Slider_BaseY->setValue(_robot->y());ui->sb_y->setValue(_robot->y());
    ui->Slider_BaseZ->setValue(_robot->z());ui->sb_z->setValue(_robot->z());
    ui->sb_a->setValue(_robot->a());
    ui->sb_b->setValue(_robot->b());
    ui->sb_c->setValue(_robot->c()); ui->Slider_BaseC->setValue(_robot->c());
    ui->sb_l1->setValue(_robot->l1());ui->Slider_BaseL1->setValue(_robot->l1());
    ui->cb_Flg1->setCurrentIndex(_robot->flg1());
    ui->spinBox_Flg2->setValue(_robot->flg2());
}

CoordinateSystem* ControlPanel::getCoord()
{
    return RotatedPoint;
}

void ControlPanel::setTransRotCoord()
{
    RotatedPoint->setTranslation(
        QVector3D(ui->lineEdit_X->text().toFloat(),ui->lineEdit_Y->text().toFloat(),ui->lineEdit_Z->text().toFloat()));
    RotatedPoint->setRotation(QQuaternion::fromEulerAngles(QVector3D(ui->lineEdit_B->text().toFloat(),ui->lineEdit_A->text().toFloat(),ui->lineEdit_C->text().toFloat())));
}
