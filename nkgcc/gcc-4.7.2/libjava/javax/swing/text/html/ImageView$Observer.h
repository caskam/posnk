
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_text_html_ImageView$Observer__
#define __javax_swing_text_html_ImageView$Observer__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Image;
    }
  }
  namespace javax
  {
    namespace swing
    {
      namespace text
      {
        namespace html
        {
            class ImageView;
            class ImageView$Observer;
        }
      }
    }
  }
}

class javax::swing::text::html::ImageView$Observer : public ::java::lang::Object
{

public: // actually package-private
  ImageView$Observer(::javax::swing::text::html::ImageView *);
public:
  virtual jboolean imageUpdate(::java::awt::Image *, jint, jint, jint, jint, jint);
public: // actually package-private
  ::javax::swing::text::html::ImageView * __attribute__((aligned(__alignof__( ::java::lang::Object)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_text_html_ImageView$Observer__