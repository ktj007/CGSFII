#include "stdafx.h"
#include "ServerListenerLogicEntry.h"

ServerListenerLogicEntry::ServerListenerLogicEntry(void)
{
}


ServerListenerLogicEntry::~ServerListenerLogicEntry(void)
{
}

bool ServerListenerLogicEntry::Initialize()
{
	return true;
}

bool ServerListenerLogicEntry::ProcessPacket(BasePacket* pPacket)
{
	switch (pPacket->GetPacketType())
	{	
	case SFPACKET_DATA:		
		SFEngine::GetInstance()->SendRequest(pPacket);
		break;
	}

	return true;
}

ILogicEntry* ServerListenerLogicEntry::Clone()
{
	return new ServerListenerLogicEntry();
}

