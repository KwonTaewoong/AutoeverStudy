// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketGameInstance.h"
#include "WebSocketsModule.h"

void UWebSocketGameInstance::Init()
{
	Super::Init();

	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket("ws://localhost:3000");

	WebSocket->OnMessage().AddLambda([this](const FString& MessageString)
		{
			this->ReceiveData = MessageString;
			OnMsgReceived.Broadcast(MessageString);
			
		});
	WebSocket->OnMessageSent().AddLambda([](const FString& MessageString)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Send message: " + MessageString);
		});

	WebSocket->Connect();
}

void UWebSocketGameInstance::Shutdown()
{
	if (WebSocket->IsConnected())
	{
		WebSocket->Close();
	}
	Super::Shutdown();
}

void UWebSocketGameInstance::SendMessage(FString Message)
{
	if (WebSocket->IsConnected())
	{
		WebSocket->Send(Message);
	}
}

FString UWebSocketGameInstance::OnRecived_Implementation(FString Message)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Received message: " + FCString::Atoi(*Message));
	return Message;
}