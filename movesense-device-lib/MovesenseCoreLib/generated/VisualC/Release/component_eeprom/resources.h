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

struct WB_ALIGN(4) EepromData;
struct WB_ALIGN(4) EepromInfo;

struct WB_ALIGN(4) EepromData
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 17408;

	WB_ALIGN(4) whiteboard::Array< uint8 > bytes;
};

struct WB_ALIGN(4) EepromInfo
{
	// Structure type identification and serialization
	typedef int Structure;
	static const whiteboard::LocalDataTypeId DATA_TYPE_ID = 17409;

	WB_ALIGN(4) whiteboard::WrapperFor32BitPointer< const char > model;
	WB_ALIGN(4) uint32 size;
};

namespace LOCAL 
{

struct ROOT;

struct COMPONENT;

struct COMPONENT_EEPROM;

struct COMPONENT_EEPROM_EEPROMINDEX
{
	static const whiteboard::ExecutionContextId EXECUTION_CONTEXT = WB_EXEC_CTX_APPLICATION;
	static const whiteboard::ResourceId::Value ID = WB_RESOURCE_VALUE(0, 17408, EXECUTION_CONTEXT);
	static const whiteboard::LocalResourceId LID = 17408;

	struct GET
	{
		typedef whiteboard::StronglyTypedResult<const EepromData&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_BAD_REQUEST> HTTP_CODE_BAD_REQUEST;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_NOT_IMPLEMENTED> HTTP_CODE_NOT_IMPLEMENTED;

		struct Parameters
		{
			struct EEPROMINDEX
			{
				static const whiteboard::ParameterIndex Index = 0;

				typedef int32 Type;
				typedef Type ConstReferenceType;
			};

			typedef EEPROMINDEX Parameter1;

			struct ADDR
			{
				static const whiteboard::ParameterIndex Index = 1;

				typedef uint32 Type;
				typedef Type ConstReferenceType;
			};

			typedef ADDR Parameter2;

			struct LEN
			{
				static const whiteboard::ParameterIndex Index = 2;

				typedef uint8 Type;
				typedef Type ConstReferenceType;
			};

			typedef LEN Parameter3;

			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 3;
		};

		/** Reference wrapper for strongly typed parameter list for /Component/Eeprom/{EepromIndex} */
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

			/** Gets EEPROMINDEX parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::EEPROMINDEX::ConstReferenceType getEepromIndex() const
			{
				return mrParameterList[Parameters::EEPROMINDEX::Index].convertTo<Parameters::EEPROMINDEX::ConstReferenceType>();
			}

			/** Gets ADDR parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::ADDR::ConstReferenceType getAddr() const
			{
				return mrParameterList[Parameters::ADDR::Index].convertTo<Parameters::ADDR::ConstReferenceType>();
			}

			/** Gets LEN parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::LEN::ConstReferenceType getLen() const
			{
				return mrParameterList[Parameters::LEN::Index].convertTo<Parameters::LEN::ConstReferenceType>();
			}

		private:
			/** Reference to actual parameter list */
			const whiteboard::ParameterList& mrParameterList;
		};

		/** Compile time type checking */
		inline static void typeCheck(
			Parameters::EEPROMINDEX::ConstReferenceType,
			Parameters::ADDR::ConstReferenceType,
			Parameters::LEN::ConstReferenceType)
		{
		}
	};

	struct PUT
	{
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_BAD_REQUEST> HTTP_CODE_BAD_REQUEST;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_NOT_IMPLEMENTED> HTTP_CODE_NOT_IMPLEMENTED;

		struct Parameters
		{
			struct EEPROMINDEX
			{
				static const whiteboard::ParameterIndex Index = 0;

				typedef int32 Type;
				typedef Type ConstReferenceType;
			};

			typedef EEPROMINDEX Parameter1;

			struct ADDR
			{
				static const whiteboard::ParameterIndex Index = 1;

				typedef uint32 Type;
				typedef Type ConstReferenceType;
			};

			typedef ADDR Parameter2;

			struct DATA
			{
				static const whiteboard::ParameterIndex Index = 2;

				typedef EepromData Type;
				typedef const Type& ConstReferenceType;
			};

			typedef DATA Parameter3;

			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 3;
		};

		/** Reference wrapper for strongly typed parameter list for /Component/Eeprom/{EepromIndex} */
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

			/** Gets EEPROMINDEX parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::EEPROMINDEX::ConstReferenceType getEepromIndex() const
			{
				return mrParameterList[Parameters::EEPROMINDEX::Index].convertTo<Parameters::EEPROMINDEX::ConstReferenceType>();
			}

			/** Gets ADDR parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::ADDR::ConstReferenceType getAddr() const
			{
				return mrParameterList[Parameters::ADDR::Index].convertTo<Parameters::ADDR::ConstReferenceType>();
			}

			/** Gets DATA parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::DATA::ConstReferenceType getData() const
			{
				return mrParameterList[Parameters::DATA::Index].convertTo<Parameters::DATA::ConstReferenceType>();
			}

		private:
			/** Reference to actual parameter list */
			const whiteboard::ParameterList& mrParameterList;
		};

		/** Compile time type checking */
		inline static void typeCheck(
			Parameters::EEPROMINDEX::ConstReferenceType,
			Parameters::ADDR::ConstReferenceType,
			Parameters::DATA::ConstReferenceType)
		{
		}
	};
};

struct COMPONENT_EEPROM_EEPROMINDEX_INFO
{
	static const whiteboard::ExecutionContextId EXECUTION_CONTEXT = WB_EXEC_CTX_APPLICATION;
	static const whiteboard::ResourceId::Value ID = WB_RESOURCE_VALUE(0, 17409, EXECUTION_CONTEXT);
	static const whiteboard::LocalResourceId LID = 17409;

	struct GET
	{
		typedef whiteboard::StronglyTypedResult<const EepromInfo&, whiteboard::HTTP_CODE_OK> HTTP_CODE_OK;
		typedef whiteboard::StronglyTypedResult<const whiteboard::NoType&, whiteboard::HTTP_CODE_NOT_IMPLEMENTED> HTTP_CODE_NOT_IMPLEMENTED;

		struct Parameters
		{
			struct EEPROMINDEX
			{
				static const whiteboard::ParameterIndex Index = 0;

				typedef int32 Type;
				typedef Type ConstReferenceType;
			};

			typedef EEPROMINDEX Parameter1;

			static const whiteboard::ParameterIndex NUMBER_OF_PARAMETERS = 1;
		};

		/** Reference wrapper for strongly typed parameter list for /Component/Eeprom/{EepromIndex}/Info */
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

			/** Gets EEPROMINDEX parameter value
			*
			* @return Current parameter value
			*/
			inline Parameters::EEPROMINDEX::ConstReferenceType getEepromIndex() const
			{
				return mrParameterList[Parameters::EEPROMINDEX::Index].convertTo<Parameters::EEPROMINDEX::ConstReferenceType>();
			}

		private:
			/** Reference to actual parameter list */
			const whiteboard::ParameterList& mrParameterList;
		};

		/** Compile time type checking */
		inline static void typeCheck(
			Parameters::EEPROMINDEX::ConstReferenceType)
		{
		}
	};
};



} // namespace LOCAL 

} // namespace WB_RES
