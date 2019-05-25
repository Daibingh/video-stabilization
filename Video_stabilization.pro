TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

include (/home/hdb/opt/qwt-6.1.4/features/qwt.prf)

SOURCES += main.cpp \
    mainwindow.cpp \
    dialog.cpp

QMAKE_CXXFLAGS += -I/home/hdb/opt/opencv/include/opencv -I/home/hdb/opt/opencv/include

LIBS += -L/home/hdb/opt/opencv/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_photo -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core

HEADERS += \
    mainwindow.h \
    utils.hpp \
    dialog.h

FORMS += window.ui \
    dialog.ui

RESOURCES += \
    res.qrc

DISTFILES +=
