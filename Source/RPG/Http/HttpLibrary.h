// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "ImageDownload/Public/WebImage.h"

class HttpLibrary
{
public:

	FString Authorization="";
	TSharedRef<IHttpRequest> RequestWithRoute(FString  route, bool IsForm = false)
	{
		FHttpModule* Http = &FHttpModule::Get();
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
		Request->SetURL(route);
		Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
		if(IsForm)
			Request->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
		else
			Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
		Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));
		if(!Authorization.IsEmpty())
			Request->SetHeader(TEXT("Authorization"), Authorization);
		return Request;
	}

	TSharedRef<IHttpRequest> GetRequest(FString Subroute)
	{
		TSharedRef<IHttpRequest> Request = RequestWithRoute(Subroute);
		Request->SetVerb("GET");  return Request;
	}
	TSharedRef<IHttpRequest> PostRequest(FString Subroute,  FString ContentJsonString)
	{
		TSharedRef<IHttpRequest> Request = RequestWithRoute(Subroute);
		Request->SetVerb("POST");
		Request->SetContentAsString(ContentJsonString);
		return Request;
	}

	TSharedRef<IHttpRequest> PostRequestAsFormData(FString Subroute,  FString ContentJsonString)
	{
		TSharedRef<IHttpRequest> Request = RequestWithRoute(Subroute, true);
		Request->SetVerb("POST");
		Request->SetContentAsString(ContentJsonString);
		return Request;
	}
	void Send(TSharedRef<IHttpRequest>& Request)
	{
		Request->ProcessRequest();
	}

	bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful)
	{
		if ((!bWasSuccessful) || (!Response.IsValid()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code:  %d"), Response->GetResponseCode());
			return false;
		}
		return true;
	}
};