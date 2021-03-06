/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerBreachWarningLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic of the Breach Warning module.


#ifndef __vtkSlicerBreachWarningLogic_h
#define __vtkSlicerBreachWarningLogic_h


#include <string>

// Slicer includes
#include "vtkSlicerModuleLogic.h"
#include "vtkSlicerMarkupsLogic.h"

// MRML includes
#include "vtkMRML.h"
#include "vtkMRMLNode.h"
#include "vtkMRMLScene.h"
#include <vtkMRMLMarkupsFiducialNode.h>
#include <vtkLandmarkTransform.h>
#include <vtkPoints.h>
#include "vtkSmartPointer.h"

// For referencing own MRML node
class vtkMRMLBreachWarningNode;


class vtkMRMLMarkupsFiducialNode;
class vtkMRMLModelNode;
class vtkMRMLLinearTransformNode;


// STD includes
#include <cstdlib>

#include "vtkSlicerBreachWarningModuleLogicExport.h"




/// \ingroup Slicer_QtModules_BreachWarning
class VTK_SLICER_BREACHWARNING_MODULE_LOGIC_EXPORT vtkSlicerBreachWarningLogic :
  public vtkSlicerModuleLogic
{
public:
  
  static vtkSlicerBreachWarningLogic *New();
  vtkTypeMacro(vtkSlicerBreachWarningLogic,vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  

  // Public interface to be used by GUI and other modules.
  
  void SetWatchedModelNode( vtkMRMLModelNode* newModel, vtkMRMLBreachWarningNode* moduleNode );
  void SetObservedTransformNode( vtkMRMLLinearTransformNode* newTransform, vtkMRMLBreachWarningNode* moduleNode );

  void SetWarningColor( double red, double green, double blue, double alpha, vtkMRMLBreachWarningNode* moduleNode );
  double GetWarningColorComponent( int c, vtkMRMLBreachWarningNode* moduleNode );
  
  void SetOriginalColor( double red, double green, double blue, double alpha, vtkMRMLBreachWarningNode* moduleNode );
  double GetOriginalColorComponent( int c, vtkMRMLBreachWarningNode* moduleNode );

  vtkSlicerMarkupsLogic* MarkupsLogic;

  void ProcessMRMLNodesEvents( vtkObject* caller, unsigned long event, void* callData );
  
protected:
  vtkSlicerBreachWarningLogic();
  virtual ~vtkSlicerBreachWarningLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene * newScene);
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);


  void UpdateModelColor( vtkMRMLBreachWarningNode* bwNode );


private:
  vtkSlicerBreachWarningLogic(const vtkSlicerBreachWarningLogic&); // Not implemented
  void operator=(const vtkSlicerBreachWarningLogic&);               // Not implemented

private:
  char* ModuleNodeID;
  vtkMRMLBreachWarningNode* ModuleNode;
};

#endif

