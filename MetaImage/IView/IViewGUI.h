// generated by Fast Light User Interface Designer (fluid) version 1.00

#ifndef IViewGUI_h
#define IViewGUI_h
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Window.H>
#include <GLSliceView.h>
#include<itkImageRegionIterator.h>

class IViewGUI {
public:
  typedef void (*ImageNumSliderCBType)(unsigned short int imageNum);
  typedef void (*OpenCBType)(void);
  typedef void (*RemoveCBType)(void);
  typedef void (*SaveCBType)(void);
private:
  ImageNumSliderCBType imageNumSliderCB;
  OpenCBType openImageCB, openOverlayCB;
  RemoveCBType removeCB;
  SaveCBType saveCB;
public:
  IViewGUI();
  ~IViewGUI();
  Fl_Window* createGUI();
  Fl_Window *iviewWindow;
  static Fl_Menu_Item menu_[];
  static Fl_Menu_Item *OpenAdd;
private:
  inline void cb_OpenAdd_i(Fl_Menu_*, void*);
  static void cb_OpenAdd(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *AddOverlay;
private:
  inline void cb_AddOverlay_i(Fl_Menu_*, void*);
  static void cb_AddOverlay(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *Remove;
private:
  inline void cb_Remove_i(Fl_Menu_*, void*);
  static void cb_Remove(Fl_Menu_*, void*);
  inline void cb_Quit_i(Fl_Menu_*, void*);
  static void cb_Quit(Fl_Menu_*, void*);
  inline void cb_Value_i(Fl_Menu_*, void*);
  static void cb_Value(Fl_Menu_*, void*);
  inline void cb_Log_i(Fl_Menu_*, void*);
  static void cb_Log(Fl_Menu_*, void*);
  inline void cb_X_i(Fl_Menu_*, void*);
  static void cb_X(Fl_Menu_*, void*);
  inline void cb_Y_i(Fl_Menu_*, void*);
  static void cb_Y(Fl_Menu_*, void*);
  inline void cb_Z_i(Fl_Menu_*, void*);
  static void cb_Z(Fl_Menu_*, void*);
  inline void cb_H_i(Fl_Menu_*, void*);
  static void cb_H(Fl_Menu_*, void*);
  inline void cb_MIP_i(Fl_Menu_*, void*);
  static void cb_MIP(Fl_Menu_*, void*);
  inline void cb_FlipX_i(Fl_Menu_*, void*);
  static void cb_FlipX(Fl_Menu_*, void*);
  inline void cb_FlipY_i(Fl_Menu_*, void*);
  static void cb_FlipY(Fl_Menu_*, void*);
  inline void cb_XY_i(Fl_Menu_*, void*);
  static void cb_XY(Fl_Menu_*, void*);
  inline void cb_XZ_i(Fl_Menu_*, void*);
  static void cb_XZ(Fl_Menu_*, void*);
  inline void cb_YZ_i(Fl_Menu_*, void*);
  static void cb_YZ(Fl_Menu_*, void*);
public:
  Fl_Value_Slider *sliceNumberSlider;
private:
  inline void cb_sliceNumberSlider_i(Fl_Value_Slider*, void*);
  static void cb_sliceNumberSlider(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *imageNumberSlider;
private:
  inline void cb_imageNumberSlider_i(Fl_Value_Slider*, void*);
  static void cb_imageNumberSlider(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *intensityWindowingMinSlider;
private:
  inline void cb_intensityWindowingMinSlider_i(Fl_Value_Slider*, void*);
  static void cb_intensityWindowingMinSlider(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *intensityWindowingMaxSlider;
private:
  inline void cb_intensityWindowingMaxSlider_i(Fl_Value_Slider*, void*);
  static void cb_intensityWindowingMaxSlider(Fl_Value_Slider*, void*);
  inline void cb_Zoom_i(Fl_Button*, void*);
  static void cb_Zoom(Fl_Button*, void*);
  inline void cb_Zoom1_i(Fl_Button*, void*);
  static void cb_Zoom1(Fl_Button*, void*);
  inline void cb_U_i(Fl_Button*, void*);
  static void cb_U(Fl_Button*, void*);
  inline void cb_Reset_i(Fl_Button*, void*);
  static void cb_Reset(Fl_Button*, void*);
  inline void cb_R_i(Fl_Button*, void*);
  static void cb_R(Fl_Button*, void*);
  inline void cb_L_i(Fl_Button*, void*);
  static void cb_L(Fl_Button*, void*);
  inline void cb_D_i(Fl_Button*, void*);
  static void cb_D(Fl_Button*, void*);
public:
  Fl_Output *selectedPointDisplay;
  Fl_Group *glWindowGroup;
  virtual void addMenuBarOptions(void);
  virtual void addFilterMenuOptions(void);
  virtual void addFileMenuOptions(void);
  virtual void open(void);
  virtual void update(void);
  virtual void show(void);
  virtual void hide(void);
  virtual void setImage(const PhysicalImage<float,3>::Pointer img);
  virtual void imageMode(ImageModeType mode);
  virtual void synchronize(void);
  virtual void shiftUp(void);
  virtual void shiftDown(void);
  virtual void shiftLeft(void);
  virtual void shiftRight(void);
  virtual void selectSlice(unsigned int);
  virtual void setIntensityWindowingMin(float);
  virtual void setIntensityWindowingMax(float);
  virtual void centerWindow(void);
  virtual void zoomIn(void);
  virtual void zoomOut(void);
  virtual void FlipX(void);
  virtual void CreateGLSliceView( Fl_Group *,Fl_Gl_Window * w );
  virtual void FlipY(void);
  virtual void Orientation(unsigned int);
};
#endif
