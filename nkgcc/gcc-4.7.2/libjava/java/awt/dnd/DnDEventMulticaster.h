
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_dnd_DnDEventMulticaster__
#define __java_awt_dnd_DnDEventMulticaster__

#pragma interface

#include <java/awt/AWTEventMulticaster.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace dnd
      {
          class DnDEventMulticaster;
          class DragSourceListener;
          class DragSourceMotionListener;
      }
    }
  }
}

class java::awt::dnd::DnDEventMulticaster : public ::java::awt::AWTEventMulticaster
{

public: // actually protected
  DnDEventMulticaster(::java::util::EventListener *, ::java::util::EventListener *);
public:
  static ::java::awt::dnd::DragSourceListener * add(::java::awt::dnd::DragSourceListener *, ::java::awt::dnd::DragSourceListener *);
  static ::java::awt::dnd::DragSourceMotionListener * add(::java::awt::dnd::DragSourceMotionListener *, ::java::awt::dnd::DragSourceMotionListener *);
  static ::java::awt::dnd::DragSourceListener * remove(::java::awt::dnd::DragSourceListener *, ::java::awt::dnd::DragSourceListener *);
  static ::java::awt::dnd::DragSourceMotionListener * remove(::java::awt::dnd::DragSourceMotionListener *, ::java::awt::dnd::DragSourceMotionListener *);
  static ::java::lang::Class class$;
};

#endif // __java_awt_dnd_DnDEventMulticaster__