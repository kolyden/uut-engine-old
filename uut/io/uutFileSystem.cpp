#include "uutFileSystem.h"
#include "uutFileStream.h"

namespace uut
{
	FileSystem::FileSystem() = default;

	SharedPtr<FileStream> FileSystem::OpenRead(const String& path)
	{
		auto stream = SharedPtr<FileStream>(new FileStream());
		if (!stream->Open(path, FileMode::OpenRead))
			return SharedPtr<FileStream>::EMPTY;

		return stream;
	}
}
