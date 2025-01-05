// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IWebSocket.h"
#include "WebSocketGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class AUTOEVERSTUDY_API UWebSocketGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void Shutdown() override;
	TSharedPtr<IWebSocket> WebSocket;

	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	void SendMessage(FString Message);

	UPROPERTY(BlueprintReadWrite, Category = "WebSocket")
	FString ReceiveData;
};
