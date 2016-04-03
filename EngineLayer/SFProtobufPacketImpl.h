#pragma once
#include "EngineLayerHeader.h"
#pragma warning( push )
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#pragma warning( pop )

#include "DataBuffer.h"

class SFProtobufPacketImpl : public BasePacket
{
public:
	SFProtobufPacketImpl(int serviceId, int channel, google::protobuf::Message* message);
	~SFProtobufPacketImpl(void);
public:
	virtual bool Decode(char* pBuf, unsigned int nSize);
	virtual bool Encode();
	virtual google::protobuf::Message& getStructuredData();
	virtual void Release() override;

private:
	int serviceId;
	int m_channel;
	std::string* pEncodedStream;
	google::protobuf::Message* message;

	DataBuffer extendedData;
	
public:
	std::string* getEncodedStream() const { return pEncodedStream; }
	int getEncodedStreamSize();	
	int getServiceId() const { return serviceId; }
	void SetChannel(int channel) { m_channel = channel; }
	int GetChannel() const { return m_channel; }

	DataBuffer* getExtendedData(){ return &extendedData; }
	int getExtendedDataSize(){ return extendedData.GetDataSize(); }
};