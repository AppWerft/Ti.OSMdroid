/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.osmdroid.ViewProxy.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"


#include "org.appcelerator.titanium.proxy.TiViewProxy.h"

#define TAG "ViewProxy"

using namespace v8;

		namespace ti {
		namespace osmdroid {
			namespace tiosmdroid {


Persistent<FunctionTemplate> ViewProxy::proxyTemplate = Persistent<FunctionTemplate>();
jclass ViewProxy::javaClass = NULL;

ViewProxy::ViewProxy(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void ViewProxy::bindProxy(Handle<Object> exports)
{
	if (proxyTemplate.IsEmpty()) {
		getProxyTemplate();
	}

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("View");

	Local<Function> proxyConstructor = proxyTemplate->GetFunction();
	exports->Set(nameSymbol, proxyConstructor);
}

void ViewProxy::dispose()
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Dispose();
		proxyTemplate = Persistent<FunctionTemplate>();
	}

	titanium::TiViewProxy::dispose();
}

Handle<FunctionTemplate> ViewProxy::getProxyTemplate()
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate;
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("ti/osmdroid/ViewProxy");
	HandleScope scope;

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("View");

	Handle<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		titanium::TiViewProxy::getProxyTemplate()
, javaClass, nameSymbol);

	proxyTemplate = Persistent<FunctionTemplate>::New(t);
	proxyTemplate->Set(titanium::Proxy::inheritSymbol,
		FunctionTemplate::New(titanium::Proxy::inherit<ViewProxy>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *proxyTemplate);

	// Method bindings --------------------------------------------------------
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "addAnnotations", ViewProxy::addAnnotations);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "zoom", ViewProxy::zoom);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "setMapType", ViewProxy::setMapType);
	DEFINE_PROTOTYPE_METHOD(proxyTemplate, "setLocation", ViewProxy::setLocation);

	Local<ObjectTemplate> prototypeTemplate = proxyTemplate->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = proxyTemplate->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return proxyTemplate;
}

// Methods --------------------------------------------------------------------
Handle<Value> ViewProxy::addAnnotations(const Arguments& args)
{
	LOGD(TAG, "addAnnotations()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ViewProxy::javaClass, "addAnnotations", "([Ljava/lang/Object;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'addAnnotations' with signature '([Ljava/lang/Object;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());


	jvalue jArguments[1];




	uint32_t length = args.Length() - 0;
	if (length < 0) {
		length = 0;
	}

	jobjectArray varArgs = env->NewObjectArray(length, titanium::JNIUtil::objectClass, NULL);
	for (uint32_t i = 0; i < length; ++i) {
		bool isNew;
		jobject arg = titanium::TypeConverter::jsValueToJavaObject(env, args[i+0], &isNew);
		env->SetObjectArrayElement(varArgs, i, arg);
		if (isNew) {
			env->DeleteLocalRef(arg);
		}
	}

	jArguments[0].l = varArgs;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}


			env->DeleteLocalRef(jArguments[0].l);

	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> ViewProxy::zoom(const Arguments& args)
{
	LOGD(TAG, "zoom()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ViewProxy::javaClass, "zoom", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'zoom' with signature '(I)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "zoom: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
		if ((titanium::V8Util::isNaN(args[0]) && !args[0]->IsUndefined()) || args[0]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> ViewProxy::setMapType(const Arguments& args)
{
	LOGD(TAG, "setMapType()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ViewProxy::javaClass, "setMapType", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMapType' with signature '(I)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setMapType: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	
	
		if ((titanium::V8Util::isNaN(args[0]) && !args[0]->IsUndefined()) || args[0]->ToString()->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			return titanium::JSException::Error(error);
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber();
		jArguments[0].i =
			titanium::TypeConverter::jsNumberToJavaInt(env, arg_0);
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}
Handle<Value> ViewProxy::setLocation(const Arguments& args)
{
	LOGD(TAG, "setLocation()");
	HandleScope scope;

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		return titanium::JSException::GetJNIEnvironmentError();
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ViewProxy::javaClass, "setLocation", "(Lorg/appcelerator/kroll/KrollDict;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setLocation' with signature '(Lorg/appcelerator/kroll/KrollDict;)V'";
			LOGE(TAG, error);
				return titanium::JSException::Error(error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setLocation: Invalid number of arguments. Expected 1 but got %d", args.Length());
		return ThrowException(Exception::Error(String::New(errorStringBuffer)));
	}

	jvalue jArguments[1];




	bool isNew_0;
	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException();
		env->ExceptionClear();
	}




	return v8::Undefined();

}

// Dynamic property accessors -------------------------------------------------


			} // namespace tiosmdroid
		} // osmdroid
		} // ti
