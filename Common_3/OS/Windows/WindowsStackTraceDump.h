/*
 * Copyright (c) 2018-2021 The Forge Interactive Inc.
 *
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

#pragma once
#include "../Interfaces/IOperatingSystem.h"
#include "../Interfaces/IThread.h"

struct WindowsStackTraceLineInfo
{
	char  mFunctionName[512];
	char  mFileName[512];
	DWORD mLineNumber;
};

class WindowsStackTrace
{
public:
	static WindowsStackTrace* pInst;

	Mutex  mDbgHelpMutex;
	size_t mUsedMemorySize;
	size_t mPreallocatedMemorySize;
	void*  pPreallocatedMemory;

	static bool Init();
	static void Exit();
	static void* Alloc(size_t size);
	static LONG Dump(EXCEPTION_POINTERS* pExceptionInfo);
};
