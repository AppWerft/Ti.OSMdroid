/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.osmdroid.TiosmdroidModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"



#include "ti.osmdroid.AnnotationProxy.h"
#include "ti.osmdroid.ViewProxy.h"

#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "TiosmdroidModule"

using namespace v8;

		namespace ti {
		namespace osmdroid {


Persistent<FunctionTemplate> TiosmdroidModule::proxyTemplate = Persistent<FunctionTemplate>();
jclass TiosmdroidModule::javaClass = NULL;

TiosmdroidModule::TiosmdroidModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void TiosmdroidModule::bindProxy(Handle<Object> exports)
{
	if (proxyTemplate.IsEmpty()) {
		getProxyTemplate();
	}

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Tiosmdroid");

	Local<Function> proxyConstructor = proxyTemplate->GetFunction();
	Local<Object> moduleInstance = proxyConstructor->NewInstance();
	exports->Set(nameSymbol, moduleInstance);
}

void TiosmdroidModule::dispose()
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Dispose();
		proxyTemplate = Persistent<FunctionTemplate>();
	}

	titanium::KrollModule::dispose();
}

Handle<FunctionTemplate> TiosmdroidModule::getProxyTemplate()
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate;
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("ti/osmdroid/TiosmdroidModule");
	HandleScope scope;

	// use symbol over string for efficiency
	Handle<String> nameSymbol = String::NewSymbol("Tiosmdroid");

	Handle<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		titanium::KrollModule::getProxyTemplate()
, javaClass, nameSymbol);

	proxyTemplate = Persistent<FunctionTemplate>::New(t);
	proxyTemplate->Set(titanium::Proxy::inheritSymbol,
		FunctionTemplate::New(titanium::Proxy::inherit<TiosmdroidModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *proxyTemplate);

	// Method bindings --------------------------------------------------------

	Local<ObjectTemplate> prototypeTemplate = proxyTemplate->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = proxyTemplate->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in TiosmdroidModule");
		//return;
	}


		DEFINE_INT_CONSTANT(prototypeTemplate, "CLOUDMADESTANDARDTILES", 2);

		DEFINE_INT_CONSTANT(prototypeTemplate, "MAPNIK", 6);

		DEFINE_INT_CONSTANT(prototypeTemplate, "CYCLEMAP", 3);

		DEFINE_INT_CONSTANT(prototypeTemplate, "MAPQUESTAERIAL_US", 8);

		DEFINE_INT_CONSTANT(prototypeTemplate, "ROADS_OVERLAY_NL", 11);

		DEFINE_INT_CONSTANT(prototypeTemplate, "PUBLIC_TRANSPORT", 10);

		DEFINE_INT_CONSTANT(prototypeTemplate, "DEFAULT_TILE_SOURCE", 4);

		DEFINE_INT_CONSTANT(prototypeTemplate, "MAPQUESTAERIAL", 7);

		DEFINE_INT_CONSTANT(prototypeTemplate, "BASE_OVERLAY_NL", 0);

		DEFINE_INT_CONSTANT(prototypeTemplate, "MAPQUESTOSM", 9);

		DEFINE_INT_CONSTANT(prototypeTemplate, "CLOUDMADESMALLTILES", 1);

		DEFINE_INT_CONSTANT(prototypeTemplate, "FIETS_OVERLAY_NL", 5);


	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return proxyTemplate;
}

// Methods --------------------------------------------------------------------

// Dynamic property accessors -------------------------------------------------


		} // osmdroid
		} // ti
