#pragma once
/***********************************************************************
* THIS FILE HAS BEEN GENERATED BY WBRES TOOL. DO NOT TRY TO CHANGE IT. *
***********************************************************************/
// Copyright (c) Suunto Oy 2014 - 2017. All rights reserved.

#include "whiteboard/Identifiers.h"
#include "whiteboard/ParameterList.h"
#include "whiteboard/Result.h"
#include "whiteboard/ResourceClient.h"

#include "whiteboard/builtinTypes/Array.h"
#include "whiteboard/builtinTypes/ByteStream.h"
#include "whiteboard/builtinTypes/Date.h"
#include "whiteboard/builtinTypes/DateTime.h"
#include "whiteboard/builtinTypes/Optional.h"
#include "whiteboard/builtinTypes/Structures.h"
#include "whiteboard/builtinTypes/Time.h"
#include "whiteboard/builtinTypes/Timestamp.h"
#include "whiteboard/builtinTypes/TypedEnum.h"
#include "whiteboard/builtinTypes/Vector2D.h"
#include "whiteboard/builtinTypes/Vector3D.h"
#include "whiteboard/builtinTypes/WrapperFor32BitPointer.h"

#define WB_RESOURCE_VALUE(whiteboardId, localResourceId, executionContextId) \
    static_cast<whiteboard::ResourceId::Value>( \
        (static_cast<uint32>(localResourceId) << 16) | \
        (static_cast<uint32>(whiteboardId) << 8) | \
        (static_cast<uint32>(executionContextId) << 4) | \
        (static_cast<uint32>(whiteboard::ID_INVALID_RESOURCE_INSTANCE)))


#include "../wb-resources/resources.h"
#include "../movesense_types/resources.h"

#define WB_EXEC_CTX_APPLICATION                  static_cast<whiteboard::ExecutionContextId>(0)
#define WB_EXEC_CTX_MEAS                         static_cast<whiteboard::ExecutionContextId>(1)

namespace WB_RES {

struct DataLoggerStateValues
{
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 13059;

	enum Type
	{
		DATALOGGER_INVALID = 1U,
		DATALOGGER_READY = 2U,
		DATALOGGER_LOGGING = 3U
	};
};
typedef whiteboard::TypedEnum<DataLoggerStateValues, DataLoggerStateValues::Type, uint8> DataLoggerState;

struct WB_ALIGN(4) DataEntry;
struct WB_ALIGN(4) DataEntryArray;
struct WB_ALIGN(4) DataLoggerConfig;

struct WB_ALIGN(4) DataEntry
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 13056;

	WB_ALIGN(4) whiteboard::WrapperFor32BitPointer< const char > path;
};

struct WB_ALIGN(4) DataEntryArray
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 13057;

	WB_ALIGN(4) whiteboard::Array< DataEntry > dataEntry;
};

struct WB_ALIGN(4) DataLoggerConfig
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 13058;

	WB_ALIGN(4) DataEntryArray dataEntries;
};

namespace LOCAL 
{

struct ROOT;

struct MEM;

struct MEM_DATALOGGER;

struct MEM_DATALOGGER_CONFIG
{
	static const whiteboard::ExecutionContextId EXECUTION_CONTEXT = WB_EXEC_CTX_APPLICATION;
	static const whiteboard::ResourceId::Value ID = WB_RESOURCE_VALUE(0, 13056, EXECUTION_CONTEXT);
	static const whiteboard::LocalResourceId LID = 13056;

	struct GET
	{
		typedef whiteboard::StronglyTypedResult<const DataLoggerConfig&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_BAD_REQUEST> HTTP_CODE_BAD_REQUEST;

		struct Parameters
		{
			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 0;
		};

		/** Compile time type checking */
		inline static void typeCheck()
		{
		}
	};

	struct PUT
	{
		typedef whiteboard::StronglyTypedResult<const DataLoggerConfig&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_BAD_REQUEST> HTTP_CODE_BAD_REQUEST;

		struct Parameters
		{
			struct CONFIG
			{
				static const whiteboard::ParameterIndex Index = 0;

				typedef DataLoggerConfig Type;
				typedef const Type& ConstReferenceType;
			};

			typedef CONFIG Parameter1;

			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 1;
		};

		/** Reference wrapper for strongly typed parameter list for /Mem/DataLogger/Config */
		class ParameterListRef
		{
		private:
			/** Prevent use of default constructor */
			ParameterListRef() DELETED;

			/** Prevent use of copy constructor */
			ParameterListRef(const ParameterListRef&) DELETED;

			/** Prevent use of assignment operator */
			const ParameterListRef& operator=(const ParameterListRef&) DELETED;

		public:
			/** Constructor that initializes this class from existing parameter list
			*
			* @param rParameterList Reference to parameter list that contains untyped parameters
			*/
			inline ParameterListRef(const whiteboard::ParameterList& rParameterList)
				: mrParameterList(rParameterList)
			{
			}

			/** Gets CONFIG parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::CONFIG::ConstReferenceType getConfig() const
			{
				return mrParameterList[Parameters::CONFIG::Index].convertTo<Parameters::CONFIG::ConstReferenceType>();
			}

		private:
			/** Reference to actual parameter list */
			const whiteboard::ParameterList& mrParameterList;
		};

		/** Compile time type checking */
		inline static void typeCheck(
			Parameters::CONFIG::ConstReferenceType)
		{
		}
	};
};

struct MEM_DATALOGGER_STATE
{
	static const whiteboard::ExecutionContextId EXECUTION_CONTEXT = WB_EXEC_CTX_APPLICATION;
	static const whiteboard::ResourceId::Value ID = WB_RESOURCE_VALUE(0, 13057, EXECUTION_CONTEXT);
	static const whiteboard::LocalResourceId LID = 13057;

	struct GET
	{
		typedef whiteboard::StronglyTypedResult<DataLoggerState, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;

		struct Parameters
		{
			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 0;
		};

		/** Compile time type checking */
		inline static void typeCheck()
		{
		}
	};

	struct PUT
	{
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_BAD_REQUEST> HTTP_CODE_BAD_REQUEST;

		struct Parameters
		{
			struct NEWSTATE
			{
				static const whiteboard::ParameterIndex Index = 0;

				typedef DataLoggerState Type;
				typedef Type ConstReferenceType;
			};

			typedef NEWSTATE Parameter1;

			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 1;
		};

		/** Reference wrapper for strongly typed parameter list for /Mem/DataLogger/State */
		class ParameterListRef
		{
		private:
			/** Prevent use of default constructor */
			ParameterListRef() DELETED;

			/** Prevent use of copy constructor */
			ParameterListRef(const ParameterListRef&) DELETED;

			/** Prevent use of assignment operator */
			const ParameterListRef& operator=(const ParameterListRef&) DELETED;

		public:
			/** Constructor that initializes this class from existing parameter list
			*
			* @param rParameterList Reference to parameter list that contains untyped parameters
			*/
			inline ParameterListRef(const whiteboard::ParameterList& rParameterList)
				: mrParameterList(rParameterList)
			{
			}

			/** Gets NEWSTATE parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::NEWSTATE::ConstReferenceType getNewState() const
			{
				return mrParameterList[Parameters::NEWSTATE::Index].convertTo<Parameters::NEWSTATE::ConstReferenceType>();
			}

		private:
			/** Reference to actual parameter list */
			const whiteboard::ParameterList& mrParameterList;
		};

		/** Compile time type checking */
		inline static void typeCheck(
			Parameters::NEWSTATE::ConstReferenceType)
		{
		}
	};

	struct POST
	{
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;

		struct Parameters
		{
			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 0;
		};

		/** Compile time type checking */
		inline static void typeCheck()
		{
		}
	};
};



} // namespace LOCAL 

} // namespace WB_RES
