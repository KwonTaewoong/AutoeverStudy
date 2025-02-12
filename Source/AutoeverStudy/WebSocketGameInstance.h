// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IWebSocket.h"
#include "WebSocketsModule.h"
#include "WebSocketGameInstance.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_Dynamic_OneParam, const FString&, Msg);
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
	FString ReceiveData = FString(TEXT(""));

	/*UFUNCTION(BlueprintCallable, Category = "WebSocket")
	void OnReceived(const FString& param);*/

	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	virtual FString OnRecived_Implementation(FString param);

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable, Category = "WebSocket")
	FDele_Dynamic_OneParam OnMsgReceived;
};
