#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "peheader.h"
using namespace std;

bool ReadBytes( FILE* fp, char* output, int numbytes );

int main( int argc, char* argv[] )
{
	FILE* exe;
	DOSHEADER dosheader;
	PEHEADER peheader;
	PEOPHEADER peoptionalheader;
	SECTIONHEADER sections[16];

	if( argc <= 1 )
	{
		cout << "Usage: peheader.exe filename.exe\\filename.dll" << endl;
		return 0;
	}

	exe = fopen( argv[1], "r" );
	if( exe == NULL )
	{
		cout << "Unable to open input file: " << argv[1] << endl;
		return 0;
	}

	ReadBytes( exe, (char*)&dosheader, sizeof(DOSHEADER) );
	fseek( exe, dosheader.PEHeaderOffset, SEEK_SET );
	ReadBytes( exe, (char*)&peheader, sizeof(PEHEADER) );
	ReadBytes( exe, (char*)&peoptionalheader, sizeof(PEOPHEADER) );
	ReadBytes( exe, (char*)&sections, sizeof(SECTIONHEADER)*16 );
	
	if( (dosheader.Signature != 0x5A4D) || (peheader.Signature != 0x4550) )
	{
		cout << "Invalid file header found!" << endl;
		fclose( exe );
		return 0;
	}
	
	cout << "Dos Header:" << endl;
	cout << "              DOS Signature: 0x" << setbase(16) << dosheader.Signature << endl;
	cout << "               LastPageSize: 0x" << setbase(16) << dosheader.LastPageSize << endl;
	cout << "           TotalPagesinFile: 0x" << setbase(16) << dosheader.TotalPagesinFile << endl;
	cout << "            RelocationItems: 0x" << setbase(16) << dosheader.RelocationItems << endl;
	cout << "       Paragraphs in Header: 0x" << setbase(16) << dosheader.ParagraphsinHeader << endl;
	cout << "   Minimum Extra Paragraphs: 0x" << setbase(16) << dosheader.MinimumExtraParagraphs << endl;
	cout << "   Maximum Extra Paragraphs: 0x" << setbase(16) << dosheader.MaximumExtraParagraphs << endl;
	cout << "      Initial Stack Segment: 0x" << setbase(16) << dosheader.InitialStackSegment << endl;
	cout << "      Initial Stack Pointer: 0x" << setbase(16) << dosheader.InitialStackPointer << endl;
	cout << "       ComplementedChecksum: 0x" << setbase(16) << dosheader.ComplementedChecksum << endl;
	cout << "Initial Instruction Pointer: 0x" << setbase(16) << dosheader.InitialInstructionPointer << endl;
	cout << "       Initial Code Segment: 0x" << setbase(16) << dosheader.InitialCodeSegment << endl;
	cout << "      RelocationTableOffset: 0x" << setbase(16) << dosheader.RelocationTableOffset << endl;
	cout << "              OverlayNumber: 0x" << setbase(16) << dosheader.OverlayNumber << endl;
	cout << "                  Reserved1: 0x" << setbase(16) << dosheader.Reserved[0] << " 0x" << dosheader.Reserved[1] << " 0x"
	     << dosheader.Reserved[2] << " 0x" << dosheader.Reserved[3] << " 0x" << dosheader.Reserved[4] << " 0x"
	     << dosheader.Reserved[5] << " 0x" << dosheader.Reserved[6] << " 0x" << dosheader.Reserved[7] << " 0x"
	     << dosheader.Reserved[8] << " 0x" << dosheader.Reserved[9] << " 0x" << dosheader.Reserved[10] << " 0x"
	     << dosheader.Reserved[11] << " 0x" << dosheader.Reserved[12] << " 0x" << dosheader.Reserved[13] << " 0x"
	     << dosheader.Reserved[14] << " 0x" << dosheader.Reserved[15] << endl;
	cout << "     Optional Header Offset: 0x" << setbase(16) << dosheader.PEHeaderOffset << endl << endl;

	cout << "PE Header:" << endl;	
	cout << "           PE Signature: 0x" << setbase(16) << peheader.Signature << endl;
	cout << "       Machine Required: 0x" << setbase(16) << peheader.MachineRequired << endl;
	cout << "     Number of Sections: 0x" << setbase(16) << peheader.NumberofSections << endl;
	cout << "          TimeDateStamp: 0x" << setbase(16) << peheader.TimeDateStamp << endl;
	cout << "        Symbols Pointer: 0x" << setbase(16) << peheader.SymbolsPointer << endl;
	cout << "      Number of Symbols: 0x" << setbase(16) << peheader.NumberofSymbols << endl;
	cout << "Size of Optional Header: 0x" << setbase(16) << peheader.SizeofOptionalHeader << endl;
	cout << "        Characteristics: 0x" << setbase(16) << peheader.Characteristics << endl << endl;
	
	cout << "PE Optional Header:" << endl;
	cout << "                                    Magic: 0x" << setbase(16) << peoptionalheader.Magic << endl;
	cout << "                            LinkerVersion: " << setbase(10) << peoptionalheader.LinkerVersion << endl;
	cout << "                             Size of Code: 0x" << setbase(16) << peoptionalheader.SizeofCode << endl;
	cout << "                  Size of InitializedData: 0x" << setbase(16) << peoptionalheader.SizeofInitializedData << endl;
	cout << "                Size of UninitializedData: 0x" << setbase(16) << peoptionalheader.SizeofUninitializedData << endl;
	cout << "                   Address of Entry Point: 0x" << setbase(16) << peoptionalheader.AddressofEntryPoint << endl;
	cout << "                             Base of Code: 0x" << setbase(16) << peoptionalheader.BaseofCode << endl;
	cout << "                             Base of Data: 0x" << setbase(16) << peoptionalheader.BaseofData << endl;
	cout << "                               Image Base: 0x" << setbase(16) << peoptionalheader.ImageBase << endl;
	cout << "                        Section Alignment: 0x" << setbase(16) << peoptionalheader.SectionAlignment << endl;
	cout << "                           File Alignment: 0x" << setbase(16) << peoptionalheader.FileAlignment << endl;
	cout << "           Major Operating System Version: " << setbase(10) << peoptionalheader.MajorOperatingSystemVersion << endl;
	cout << "           Minor Operating System Version: " << setbase(10) << peoptionalheader.MinorOperatingSystemVersion << endl;
	cout << "                      Major Image Version: " << setbase(10) << peoptionalheader.MajorImageVersion << endl;
	cout << "                      Minor Image Version: " << setbase(10) << peoptionalheader.MinorImageVersion << endl;
	cout << "                  Major Subsystem Version: " << setbase(10) << peoptionalheader.MajorSubsystemVersion << endl;
	cout << "                  Minor Subsystem Version: " << setbase(10) << peoptionalheader.MinorSubsystemVersion << endl;
	cout << "                                Reserved1: 0x" << setbase(16) << peoptionalheader.Reserved1 << endl;
	cout << "                            Size of Image: 0x" << setbase(16) << peoptionalheader.SizeofImage << endl;
	cout << "                          Size of Headers: 0x" << setbase(16) << peoptionalheader.SizeofHeaders << endl;
	cout << "                                 Checksum: 0x" << setbase(16) << peoptionalheader.Checksum << endl;
	cout << "                                Subsystem: 0x" << setbase(16) << peoptionalheader.Subsystem << endl;
	cout << "                      DLL Characteristics: 0x" << setbase(16) << peoptionalheader.DLLCharacteristics << endl;
	cout << "                    Size of Stack Reserve: 0x" << setbase(16) << peoptionalheader.SizeofStackReserve << endl;
	cout << "                     Size of Stack Commit: 0x" << setbase(16) << peoptionalheader.SizeofStackCommit << endl;
	cout << "                     Size of Heap Reserve: 0x" << setbase(16) << peoptionalheader.SizeofHeapReserve << endl;
	cout << "                      Size of Heap Commit: 0x" << setbase(16) << peoptionalheader.SizeofHeapCommit << endl;
	cout << "                             Loader Flags: 0x" << setbase(16) << peoptionalheader.LoaderFlags << endl;
	cout << "                  Number of RVA and Sizes: 0x" << setbase(16) << peoptionalheader.NumberofRVAandSizes << endl;
	cout << "         Export Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.ExportDirectoryVirtualAddress << endl;
	cout << "                    Export Directory Size: 0x" << setbase(16) << peoptionalheader.ExportDirectorySize << endl;
	cout << "         Import Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.ImportDirectoryVirtualAddress << endl;
	cout << "                    Import Directory Size: 0x" << setbase(16) << peoptionalheader.ImportDirectorySize << endl;
	cout << "       Resource Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.ResourceDirectoryVirtualAddress << endl;
	cout << "                  Resource Directory Size: 0x" << setbase(16) << peoptionalheader.ResourceDirectorySize << endl;
	cout << "      Exception Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.ExceptionDirectoryVirtualAddress << endl;
	cout << "                 Exception Directory Size: 0x" << setbase(16) << peoptionalheader.ExceptionDirectorySize << endl;
	cout << "    Certificate Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.CertificateDirectoryVirtualAddress << endl;
	cout << "               Certificate Directory Size: 0x" << setbase(16) << peoptionalheader.CertificateDirectorySize << endl;
	cout << "Base Relocation Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.BaseRelocationDirectoryVirtualAddress << endl;
	cout << "           Base Relocation Directory Size: 0x" << setbase(16) << peoptionalheader.BaseRelocationDirectorySize << endl;
	cout << "                    Debug Virtual Address: 0x" << setbase(16) << peoptionalheader.DebugVirtualAddress << endl;
	cout << "                               Debug Size: 0x" << setbase(16) << peoptionalheader.DebugSize << endl;
	cout << "             Architecture Virtual Address: 0x" << setbase(16) << peoptionalheader.ArchitectureVirtualAddress << endl;
	cout << "                        Architecture Size: 0x" << setbase(16) << peoptionalheader.ArchitectureSize << endl;
	cout << "               Global Ptr Virtual Address: 0x" << setbase(16) << peoptionalheader.GlobalPtrVirtualAddress << endl;
	cout << "                          Global Ptr Size: 0x" << setbase(16) << peoptionalheader.GlobalPtrSize << endl;
	cout << "            TLS Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.TLSDirectoryVirtualAddress << endl;
	cout << "                       TLS Directory Size: 0x" << setbase(16) << peoptionalheader.TLSDirectorySize << endl;
	cout << "    Load Config Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.LoadConfigDirectoryVirtualAddress << endl;
	cout << "               Load Config Directory Size: 0x" << setbase(16) << peoptionalheader.LoadConfigDirectorySize << endl;
	cout << "   Bound Import Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.BoundImportDirectoryVirtualAddress << endl;
	cout << "              Bound Import Directory Size: 0x" << setbase(16) << peoptionalheader.BoundImportDirectorySize << endl;
	cout << "            IAT Directory Virtual Address: 0x" << setbase(16) << peoptionalheader.IATDirectoryVirtualAddress << endl;
	cout << "                       IAT Directory Size: 0x" << setbase(16) << peoptionalheader.IATDirectorySize << endl;
	cout << "  Delay Import Descriptor Virtual Address: 0x" << setbase(16) << peoptionalheader.DelayImportDescriptorVirtualAddress << endl;
	cout << "             Delay Import Descriptor Size: 0x" << setbase(16) << peoptionalheader.DelayImportDescriptorSize << endl;
	cout << "       COM Runtime Header Virtual Address: 0x" << setbase(16) << peoptionalheader.COMRuntimeHeaderVirtualAddress << endl;
	cout << "                  COM Runtime Header Size: 0x" << setbase(16) << peoptionalheader.COMRuntimeHeaderSize << endl << endl;
	
	for( int i = 0; i < peheader.NumberofSections; i++ )
	{
		cout << "Section: " << sections[i].SectionName << endl;
		cout << "           Virtual Size: 0x" << setbase(16) << sections[i].VirtualSize << endl;
		cout << "        Virtual Address: 0x" << setbase(16) << sections[i].VirtualAddress << endl;
		cout << "       Size of Raw Data: 0x" << setbase(16) << sections[i].SizeofRawData << endl;
		cout << "    Pointer to Raw Data: 0x" << setbase(16) << sections[i].PointertoRawData << endl;
		cout << " Pointer to Relocations: 0x" << setbase(16) << sections[i].PointertoRelocations << endl;
		cout << "Pointer to Line Numbers: 0x" << setbase(16) << sections[i].PointertoLineNumbers << endl;
		cout << "  Number of Relocations: 0x" << setbase(16) << sections[i].NumberofRelocations << endl;
		cout << " Number of Line Numbers: 0x" << setbase(16) << sections[i].NumberofLineNumbers << endl;
		cout << "        Characteristics: 0x" << setbase(16) << sections[i].Characteristics << endl << endl;
	}

	fclose( exe );

	return 0;
}

bool ReadBytes( FILE* fp, char* output, int numbytes )
{
	if( fp == NULL ) return false;
	
	for( int i = 0; i < numbytes; i++ )
	{
		*output = fgetc( fp );
		output++;
	}
	
	return true;
}
