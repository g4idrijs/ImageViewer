/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    MaximumLikelihoodRatioDecisionRule.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2001 Insight Consortium
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * The name of the Insight Consortium, nor the names of any consortium members,
   nor of any contributors, may be used to endorse or promote products derived
   from this software without specific prior written permission.

  * Modified source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#include "MaximumLikelihoodRatioDecisionRule.h"

MaximumLikelihoodRatioDecisionRule::MaximumLikelihoodRatioDecisionRule() 
{
  m_TotalSampleSize = 0 ;
}

unsigned int 
MaximumLikelihoodRatioDecisionRule::Evaluate(std::vector< double > discriminantScores)
{
  unsigned int maxIndex = 0 ;
  double maxScore = 0.0 ;
  unsigned int i ;
  
  for (i = 0 ; i < m_ClassSizes.size() ; i++)
    {
      m_TempScores[i] = discriminantScores[i] * m_ClassSizes[i] ;
    }

  for (i = 0 ; i < m_ClassSizes.size() ; i++)
    {
      if (m_TempScores[i] > maxScore)
        {
          maxIndex = i ;
          maxScore = m_TempScores[i] ;
        }
    }

  return maxIndex ;
}

void MaximumLikelihoodRatioDecisionRule::AddClassSampleSize(unsigned int size)
{
  m_ClassSizes.push_back(size) ;
  m_APrioriRatioMatrix.resize(m_ClassSizes.size(), m_ClassSizes.size()) ;
  m_TempScores.resize(m_ClassSizes.size()) ;
  m_TotalSampleSize += size ;
  unsigned int row, column ;
  double APrioriRatio ;
  for (row = 0 ; row < m_ClassSizes.size() ; row++)
    {
      for (column = 0 ; column < m_ClassSizes.size() ; column++)
        {
          APrioriRatio = (double)m_ClassSizes[column] / (double)m_ClassSizes[row] ;
          m_APrioriRatioMatrix.put(row, column, APrioriRatio) ;
        }
    }
}










