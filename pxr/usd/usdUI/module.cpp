//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/pxr.h"
#include "pxr/base/tf/pyModule.h"

PXR_NAMESPACE_USING_DIRECTIVE

TF_WRAP_MODULE
{
    TF_WRAP(UsdUIAccessibilityAPI);
    TF_WRAP(UsdUIBackdrop);
    TF_WRAP(UsdUILocalizationAPI);
    TF_WRAP(UsdUINodeGraphNodeAPI); 
    TF_WRAP(UsdUISceneGraphPrimAPI);
    TF_WRAP(UsdUITokens);
}
