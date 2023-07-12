// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DrawDebugHelpers.h"

#define print(Text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT(Text), false); 
#define print_k(Key, Text) if(GEngine) GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::Red, TEXT(Text)); 
#define printf(Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT(Format), ##__VA_ARGS__), false);
#define printf_k(Key, Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::Red, FString::Printf(TEXT(Format), ##__VA_ARGS__));
#define printf_c(Color, Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, Color, FString::Printf(TEXT(Format), ##__VA_ARGS__), false);
#define print_c(Color, Text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, Color, TEXT(Text), false); 

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);
#define DRAW_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_LINE_SingleFrame(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f);
#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true);
#define DRAW_POINT_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, false, -1.f);
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
{ \
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, true); \
}
#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation) if (GetWorld()) \
{ \
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f); \
DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, false, -1.f); \