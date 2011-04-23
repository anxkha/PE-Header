#ifndef _PEHEADER_H
#define _PEHEADER_H

struct DOSHEADER
{
	unsigned short Signature;
	unsigned short LastPageSize;
	unsigned short TotalPagesinFile;
	unsigned short RelocationItems;
	unsigned short ParagraphsinHeader;
	unsigned short MinimumExtraParagraphs;
	unsigned short MaximumExtraParagraphs;
	unsigned short InitialStackSegment;
	unsigned short InitialStackPointer;
	unsigned short ComplementedChecksum;
	unsigned short InitialInstructionPointer;
	unsigned short InitialCodeSegment;
	unsigned short RelocationTableOffset;
	unsigned short OverlayNumber;
	unsigned short Reserved[16];
	unsigned long  PEHeaderOffset;
};

struct PEHEADER
{
	unsigned long  Signature;
	unsigned short MachineRequired;
	unsigned short NumberofSections;
	unsigned long  TimeDateStamp;
	unsigned long  SymbolsPointer;
	unsigned long  NumberofSymbols;
	unsigned short SizeofOptionalHeader;
	unsigned short Characteristics;
};

struct PEOPHEADER
{
	unsigned short Magic;
	unsigned short LinkerVersion;
	unsigned long  SizeofCode;
	unsigned long  SizeofInitializedData;
	unsigned long  SizeofUninitializedData;
	unsigned long  AddressofEntryPoint;
	unsigned long  BaseofCode;
	unsigned long  BaseofData;
	unsigned long  ImageBase;
	unsigned long  SectionAlignment;
	unsigned long  FileAlignment;
	unsigned short MajorOperatingSystemVersion;
	unsigned short MinorOperatingSystemVersion;
	unsigned short MajorImageVersion;
	unsigned short MinorImageVersion;
	unsigned short MajorSubsystemVersion;
	unsigned short MinorSubsystemVersion;
	unsigned long  Reserved1;
	unsigned long  SizeofImage;
	unsigned long  SizeofHeaders;
	unsigned long  Checksum;
	unsigned short Subsystem;
	unsigned short DLLCharacteristics;
	unsigned long  SizeofStackReserve;
	unsigned long  SizeofStackCommit;
	unsigned long  SizeofHeapReserve;
	unsigned long  SizeofHeapCommit;
	unsigned long  LoaderFlags;
	unsigned long  NumberofRVAandSizes;
	unsigned long  ExportDirectoryVirtualAddress;
	unsigned long  ExportDirectorySize;
	unsigned long  ImportDirectoryVirtualAddress;
	unsigned long  ImportDirectorySize;
	unsigned long  ResourceDirectoryVirtualAddress;
	unsigned long  ResourceDirectorySize;
	unsigned long  ExceptionDirectoryVirtualAddress;
	unsigned long  ExceptionDirectorySize;
	unsigned long  CertificateDirectoryVirtualAddress;
	unsigned long  CertificateDirectorySize;
	unsigned long  BaseRelocationDirectoryVirtualAddress;
	unsigned long  BaseRelocationDirectorySize;
	unsigned long  DebugVirtualAddress;
	unsigned long  DebugSize;
	unsigned long  ArchitectureVirtualAddress;
	unsigned long  ArchitectureSize;
	unsigned long  GlobalPtrVirtualAddress;
	unsigned long  GlobalPtrSize;
	unsigned long  TLSDirectoryVirtualAddress;
	unsigned long  TLSDirectorySize;
	unsigned long  LoadConfigDirectoryVirtualAddress;
	unsigned long  LoadConfigDirectorySize;
	unsigned long  BoundImportDirectoryVirtualAddress;
	unsigned long  BoundImportDirectorySize;
	unsigned long  IATDirectoryVirtualAddress;
	unsigned long  IATDirectorySize;
	unsigned long  DelayImportDescriptorVirtualAddress;
	unsigned long  DelayImportDescriptorSize;
	unsigned long  COMRuntimeHeaderVirtualAddress;
	unsigned long  COMRuntimeHeaderSize;
	unsigned long  Reserved2[2];
};

struct SECTIONHEADER
{
	unsigned char  SectionName[8];
	unsigned long  VirtualSize;
	unsigned long  VirtualAddress;
	unsigned long  SizeofRawData;
	unsigned long  PointertoRawData;
	unsigned long  PointertoRelocations;
	unsigned long  PointertoLineNumbers;
	unsigned short NumberofRelocations;
	unsigned short NumberofLineNumbers;
	unsigned long  Characteristics;
};

struct IMPORTTABLE
{
	unsigned long  ImportTableAddress;
	unsinged long  TimeDateStamp;
	unsigned long  ForwarderChain;
	unsinged long  NameAddress;
	unsinged long  ThunkTableAddress;
};

struct IMPORTENTRY
{
	unsigned long  entry;
};

struct HINTENTRY
{
	unsigned short Hint;
	unsigned char* Name;
	unsigned char  Pad;
};

#endif /* _PEHEADER_H */
