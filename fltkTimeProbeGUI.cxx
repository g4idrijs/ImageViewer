/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    fltkTimeProbeGUI.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "fltkTimeProbeGUI.h"


namespace fltk
{




TimeProbeGUI
::TimeProbeGUI():Fl_Tile(0,0,10,10,"")
{

  const unsigned int nameWidth    = 150;
  const unsigned int startsWidth  =  50;
  const unsigned int stopsWidth   =  50;
  const unsigned int timeWidth    =  50;

  const unsigned int rowHeight   =  25;

  const unsigned int width = nameWidth   + 
                             startsWidth +
                             stopsWidth  +
                             timeWidth;

  const unsigned int ly = 0;

  this->size( width, rowHeight );

  unsigned int column = 0;

  m_Name = new Fl_Output(column,ly,nameWidth,rowHeight);
  
  column += nameWidth;
  m_NumberOfStarts = new Fl_Value_Output(column,ly,startsWidth,rowHeight);
  
  column += startsWidth;
  m_NumberOfStops  = new Fl_Value_Output(column,ly,stopsWidth,rowHeight);
  
  column += stopsWidth;
  m_MeanTime      = new Fl_Value_Output(column,ly,timeWidth,rowHeight);
  
  this->end();

}



TimeProbeGUI
::~TimeProbeGUI()
{

}



void
TimeProbeGUI
::SetName( const std::string & name )
{
  m_Name->value( name.c_str() );
}




void 
TimeProbeGUI
::SetNumberOfStarts( unsigned int numstarts )
{
  m_NumberOfStarts->value( numstarts );
}



void 
TimeProbeGUI
::SetNumberOfStops( unsigned int numstops )
{
  m_NumberOfStops->value( numstops );
}


void 
TimeProbeGUI
::SetMeanTime( double meantime)
{
  m_MeanTime->value( meantime );

}


} // end namespace fltk
