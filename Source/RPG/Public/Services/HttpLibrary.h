// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "ConfigUtils/Utils.h"
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
		Request->SetContentAsString(TransformJsonToFormData(ContentJsonString));
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

	FString TransformJsonToFormData(FString JsonString) const
	{
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

		if (FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			FString FormData;
			bool bFirstEntry = true;

			for (const auto& Entry : JsonObject->Values)
			{
				FString Key = Entry.Key;
				FString Value = Entry.Value->AsString();

				if (!bFirstEntry)
				{
					FormData += "&";
				}

				FormData += FString::Printf(TEXT("%s=%s"), *Key, *Value);
				bFirstEntry = false;
			}
			printf("FormData Result: %s", *FormData);
			return FormData;
		}
		else
		{
			print("Failed to convert");
			return "";
		}
	}
};