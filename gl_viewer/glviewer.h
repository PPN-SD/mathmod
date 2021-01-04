/***************************************************************************
 *   Copyright (C) 2021 by Abderrahman Taha                                *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor,Boston, MA 02110-1301 USA             *
 ***************************************************************************/
#ifndef GLVIEWER_h
#define GLVIEWER_h

#include "../pariso/isosurface/Iso3D.h"
#include "../pariso/parametric/Model3D.h"
#include "qglthread.h"
#include "raster.h"
#include <QFileDialog>
#include <QGLWidget>
#include <QMessageBox>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QTextStream>
#include <QTimer>
#include <iostream>
#include <math.h>
#include <qpixmap.h>
#include <qthread.h>
#include <stdlib.h>
#include <string>

class OpenGlWidget : public QGLWidget
{
    Q_OBJECT
public:
    uint Ugrid, Vgrid, CutV, CutU;
    int btgauche, btdroit, btmilieu, latence, IDGlWindow;
    int Xgrid, Ygrid, Zgrid, CutX, CutY, CutZ, TypeTriangle;
    QTimer *timer;
    double Axe_x, Axe_y, Axe_z, angle, val1, val2, val3, old_x, old_y, old_z,
    factx=1.0, facty=1.0, factz=1.0;
    ObjectProperties LocalScene;
    QString FramesDir;
    Iso3D *IsoObjet;
    Par3D *ParObjet;
    int TypeFormule;
    QMessageBox message;
    ErrorMessage stError;
    GLfloat oldminx, oldminy, oldminz, oldmaxx, oldmaxy, oldmaxz;
    ImprovedNoise *PerlinNoise;

public:
    OpenGlWidget(QWidget *parent = nullptr);
    ~OpenGlWidget();
    void Winitialize_GL();
    void resizeGL(int, int);
    void paintGL();
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    virtual void run();
    void InitSpecularParameters();
    void Shininess(int);
    void initbox();
    int memoryallocation(uint, uint initpargrid = 50, uint initgrid = 40,
                         uint factx = 4, uint facty = 4, uint factz = 4);
    void deleteAllListes();
    void deleteVBO();
    void PutObjectInsideCube();
    void screenshot();
    void FramesShot();
    void FramesSave();
    QImage Copyscreenshot();

public:
    GLThread glt;
    void startRendering();
    void stopRendering();
    void resizeEvent(QResizeEvent *evt);
    void closeEvent(QCloseEvent *evt);

public slots:
    void anim();
    void morph();
    void starttimer();
    void stoptimer();
    bool timeractif();
    void restarttimer(int);
    void PrintInfos();
    void infosok();
    void FillOk();
    void normOk();
    void infosOk();
    void boundingboxOk();
    void smoothline();
    void transparency(int, int currentposition = 0);
    void red(int, int currentposition = 0);
    void green(int, int currentposition = 0);
    void blue(int, int currentposition = 0);
    void transparence(bool);
    void redSpec(int);
    void greenSpec(int);
    void blueSpec(int);
    void transSpec(int);
    void quality(int);
    void bmp();
    void jpg();
    void png();
    void colorstype(int);
    void colorstypeParIso(int);
    void colorstypeParam(int);
    void SaveSceneAsObjPoly(int n = 0);
    void SaveSceneAsObjTrian(int n = 0);
    void CalculateTexturePoints(int type);
    void CalculatePigmentPoints(int type);
    void UpdateGL();
};

#endif
