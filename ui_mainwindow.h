/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClassical;
    QAction *actionClub;
    QAction *actionDance;
    QAction *actionFull_Bass_Treble;
    QAction *actionFull_Treble;
    QAction *actionPop;
    QAction *actionReggae;
    QAction *actionRock;
    QAction *actionTechno;
    QAction *actionOpen_wav;
    QAction *actionFlat;
    QAction *actionZero;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSlider *volumeSlider;
    QSlider *f32Slider;
    QSlider *f64Slider;
    QSlider *f125Slider;
    QSlider *f250Slider;
    QSlider *f500Slider;
    QSlider *f1kSlider;
    QSlider *f2kSlider;
    QSlider *f4kSlider;
    QSlider *f8kSlider;
    QSlider *f16kSlider;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_11;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QToolButton *fileButton;
    QLineEdit *fileEdit;
    QRadioButton *radioReverb;
    QRadioButton *radioBarras;
    QMenuBar *menuBar;
    QMenu *menuPreset;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(813, 809);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush2(QColor(159, 158, 158, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setAnimated(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionClassical = new QAction(MainWindow);
        actionClassical->setObjectName(QStringLiteral("actionClassical"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagenes/classical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClassical->setIcon(icon);
        actionClassical->setIconVisibleInMenu(true);
        actionClub = new QAction(MainWindow);
        actionClub->setObjectName(QStringLiteral("actionClub"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/club.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClub->setIcon(icon1);
        actionDance = new QAction(MainWindow);
        actionDance->setObjectName(QStringLiteral("actionDance"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imagenes/dance2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDance->setIcon(icon2);
        actionFull_Bass_Treble = new QAction(MainWindow);
        actionFull_Bass_Treble->setObjectName(QStringLiteral("actionFull_Bass_Treble"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imagenes/fullbasstreble2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFull_Bass_Treble->setIcon(icon3);
        actionFull_Treble = new QAction(MainWindow);
        actionFull_Treble->setObjectName(QStringLiteral("actionFull_Treble"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imagenes/fulltreble2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFull_Treble->setIcon(icon4);
        actionPop = new QAction(MainWindow);
        actionPop->setObjectName(QStringLiteral("actionPop"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/imagenes/pop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPop->setIcon(icon5);
        actionReggae = new QAction(MainWindow);
        actionReggae->setObjectName(QStringLiteral("actionReggae"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/imagenes/reggae3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReggae->setIcon(icon6);
        actionRock = new QAction(MainWindow);
        actionRock->setObjectName(QStringLiteral("actionRock"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/imagenes/rock4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRock->setIcon(icon7);
        actionTechno = new QAction(MainWindow);
        actionTechno->setObjectName(QStringLiteral("actionTechno"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/imagenes/techno2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionTechno->setIcon(icon8);
        actionOpen_wav = new QAction(MainWindow);
        actionOpen_wav->setObjectName(QStringLiteral("actionOpen_wav"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/imagenes/openwav.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_wav->setIcon(icon9);
        actionFlat = new QAction(MainWindow);
        actionFlat->setObjectName(QStringLiteral("actionFlat"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/imagenes/flat.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlat->setIcon(icon10);
        actionZero = new QAction(MainWindow);
        actionZero->setObjectName(QStringLiteral("actionZero"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/imagenes/zero.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZero->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 791, 232));
        horizontalLayout_4 = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_2->addWidget(label_13);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(718, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 290, 791, 151));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        volumeSlider = new QSlider(layoutWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(50);
        volumeSlider->setValue(25);
        volumeSlider->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumeSlider);

        f32Slider = new QSlider(layoutWidget);
        f32Slider->setObjectName(QStringLiteral("f32Slider"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(255, 255, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush4(QColor(240, 240, 240, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        f32Slider->setPalette(palette1);
        f32Slider->setMaximum(50);
        f32Slider->setValue(25);
        f32Slider->setOrientation(Qt::Vertical);
        f32Slider->setTickPosition(QSlider::TicksBothSides);
        f32Slider->setTickInterval(5);

        horizontalLayout_2->addWidget(f32Slider);

        f64Slider = new QSlider(layoutWidget);
        f64Slider->setObjectName(QStringLiteral("f64Slider"));
        f64Slider->setMaximum(50);
        f64Slider->setValue(25);
        f64Slider->setOrientation(Qt::Vertical);
        f64Slider->setTickPosition(QSlider::TicksBothSides);
        f64Slider->setTickInterval(5);

        horizontalLayout_2->addWidget(f64Slider);

        f125Slider = new QSlider(layoutWidget);
        f125Slider->setObjectName(QStringLiteral("f125Slider"));
        f125Slider->setMaximum(50);
        f125Slider->setValue(25);
        f125Slider->setOrientation(Qt::Vertical);
        f125Slider->setTickPosition(QSlider::TicksBothSides);
        f125Slider->setTickInterval(5);

        horizontalLayout_2->addWidget(f125Slider);

        f250Slider = new QSlider(layoutWidget);
        f250Slider->setObjectName(QStringLiteral("f250Slider"));
        f250Slider->setMaximum(50);
        f250Slider->setSliderPosition(25);
        f250Slider->setOrientation(Qt::Vertical);
        f250Slider->setTickPosition(QSlider::TicksBothSides);
        f250Slider->setTickInterval(5);

        horizontalLayout_2->addWidget(f250Slider);

        f500Slider = new QSlider(layoutWidget);
        f500Slider->setObjectName(QStringLiteral("f500Slider"));
        f500Slider->setMaximum(50);
        f500Slider->setValue(25);
        f500Slider->setOrientation(Qt::Vertical);
        f500Slider->setTickPosition(QSlider::TicksBothSides);
        f500Slider->setTickInterval(5);

        horizontalLayout_2->addWidget(f500Slider);

        f1kSlider = new QSlider(layoutWidget);
        f1kSlider->setObjectName(QStringLiteral("f1kSlider"));
        f1kSlider->setMaximum(50);
        f1kSlider->setValue(25);
        f1kSlider->setOrientation(Qt::Vertical);
        f1kSlider->setTickPosition(QSlider::TicksBothSides);
        f1kSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(f1kSlider);

        f2kSlider = new QSlider(layoutWidget);
        f2kSlider->setObjectName(QStringLiteral("f2kSlider"));
        f2kSlider->setMaximum(50);
        f2kSlider->setValue(25);
        f2kSlider->setSliderPosition(25);
        f2kSlider->setOrientation(Qt::Vertical);
        f2kSlider->setTickPosition(QSlider::TicksBothSides);
        f2kSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(f2kSlider);

        f4kSlider = new QSlider(layoutWidget);
        f4kSlider->setObjectName(QStringLiteral("f4kSlider"));
        f4kSlider->setMaximum(50);
        f4kSlider->setValue(25);
        f4kSlider->setOrientation(Qt::Vertical);
        f4kSlider->setTickPosition(QSlider::TicksBothSides);
        f4kSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(f4kSlider);

        f8kSlider = new QSlider(layoutWidget);
        f8kSlider->setObjectName(QStringLiteral("f8kSlider"));
        f8kSlider->setMaximum(50);
        f8kSlider->setValue(25);
        f8kSlider->setOrientation(Qt::Vertical);
        f8kSlider->setTickPosition(QSlider::TicksBothSides);
        f8kSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(f8kSlider);

        f16kSlider = new QSlider(layoutWidget);
        f16kSlider->setObjectName(QStringLiteral("f16kSlider"));
        f16kSlider->setMaximum(50);
        f16kSlider->setValue(25);
        f16kSlider->setOrientation(Qt::Vertical);
        f16kSlider->setTickPosition(QSlider::TicksBothSides);
        f16kSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(f16kSlider);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 450, 791, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        QPalette palette2;
        QBrush brush5(QColor(170, 255, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_2->setPalette(palette2);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_11);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);

        fileButton = new QToolButton(centralWidget);
        fileButton->setObjectName(QStringLiteral("fileButton"));
        fileButton->setEnabled(true);
        fileButton->setGeometry(QRect(774, 11, 26, 24));
        fileEdit = new QLineEdit(centralWidget);
        fileEdit->setObjectName(QStringLiteral("fileEdit"));
        fileEdit->setEnabled(true);
        fileEdit->setGeometry(QRect(11, 11, 751, 25));
        radioReverb = new QRadioButton(centralWidget);
        radioReverb->setObjectName(QStringLiteral("radioReverb"));
        radioReverb->setGeometry(QRect(20, 510, 21, 23));
        radioReverb->setChecked(true);
        radioReverb->setAutoExclusive(false);
        radioBarras = new QRadioButton(centralWidget);
        radioBarras->setObjectName(QStringLiteral("radioBarras"));
        radioBarras->setGeometry(QRect(780, 530, 16, 23));
        radioBarras->setChecked(true);
        radioBarras->setAutoExclusive(false);
        MainWindow->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        fileEdit->raise();
        fileButton->raise();
        radioReverb->raise();
        radioBarras->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 813, 22));
        menuPreset = new QMenu(menuBar);
        menuPreset->setObjectName(QStringLiteral("menuPreset"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setAutoFillBackground(true);
        mainToolBar->setIconSize(QSize(36, 36));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPreset->menuAction());
        menuPreset->addAction(actionFlat);
        menuPreset->addAction(actionClassical);
        menuPreset->addAction(actionClub);
        menuPreset->addAction(actionDance);
        menuPreset->addAction(actionFull_Bass_Treble);
        menuPreset->addAction(actionFull_Treble);
        menuPreset->addAction(actionPop);
        menuPreset->addAction(actionReggae);
        menuPreset->addAction(actionRock);
        menuPreset->addAction(actionTechno);
        menuPreset->addAction(actionZero);
        menuFile->addAction(actionOpen_wav);
        mainToolBar->addAction(actionOpen_wav);
        mainToolBar->addAction(actionFlat);
        mainToolBar->addAction(actionClassical);
        mainToolBar->addAction(actionDance);
        mainToolBar->addAction(actionClub);
        mainToolBar->addAction(actionFull_Bass_Treble);
        mainToolBar->addAction(actionFull_Treble);
        mainToolBar->addAction(actionPop);
        mainToolBar->addAction(actionReggae);
        mainToolBar->addAction(actionRock);
        mainToolBar->addAction(actionTechno);
        mainToolBar->addAction(actionZero);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionClassical->setText(QApplication::translate("MainWindow", "Classical", nullptr));
        actionClub->setText(QApplication::translate("MainWindow", "Club", nullptr));
        actionDance->setText(QApplication::translate("MainWindow", "Dance", nullptr));
        actionFull_Bass_Treble->setText(QApplication::translate("MainWindow", "Full Bass & Treble", nullptr));
        actionFull_Treble->setText(QApplication::translate("MainWindow", "Full Treble", nullptr));
        actionPop->setText(QApplication::translate("MainWindow", "Pop", nullptr));
        actionReggae->setText(QApplication::translate("MainWindow", "Reggae", nullptr));
        actionRock->setText(QApplication::translate("MainWindow", "Rock", nullptr));
        actionTechno->setText(QApplication::translate("MainWindow", "Techno", nullptr));
        actionOpen_wav->setText(QApplication::translate("MainWindow", "Open .wav", nullptr));
        actionFlat->setText(QApplication::translate("MainWindow", "Flat", nullptr));
        actionZero->setText(QApplication::translate("MainWindow", "Zero", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "12dB", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "-12dB", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Volumen", nullptr));
        label->setText(QApplication::translate("MainWindow", "32", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "64", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "125", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "250", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "500", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "1k", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "2k", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "4k", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "8k", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "16k", nullptr));
        fileButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        radioReverb->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        radioBarras->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        menuPreset->setTitle(QApplication::translate("MainWindow", "Preset", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
