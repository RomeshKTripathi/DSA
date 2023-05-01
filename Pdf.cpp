#include <iostream>
#include <fpdf.h>

void CreatePDF(const std::string& text_file_path, const std::string& pdf_file_path) {
    // Initialize the library
    FPDF_LIBRARY_CONFIG config;
    config.version = 2;
    config.m_pUserFontPaths = NULL;
    config.m_pIsolate = NULL;
    config.m_v8EmbedderSlot = 0;
    FPDF_InitLibraryWithConfig(&config);

    // Create a new document
    FPDF_DOCUMENT pdf_doc = FPDF_CreateNewDocument();

    // Add a new page to the document
    FPDF_PAGE pdf_page = FPDF_AddPage(pdf_doc);

    // Set the font
    FPDF_FONT font = FPDF_LoadStandardFont(pdf_doc, "Arial");

    // Set the font size
    FPDF_SetFontSize(pdf_page, 12);

    // Open the text file
    std::ifstream text_file(text_file_path);
    std::string line;

    // Write the text to the PDF
    int y = 10;
    while (std::getline(text_file, line)) {
        FPDF_TextOut(pdf_page, 10, y, line.c_str(), line.size());
        y += 12;
    }

    // Save the PDF to a file
    FPDF_SaveAsCopy(pdf_doc, pdf_file_path.c_str(), 0);

    // Clean up
    FPDF_CloseDocument(pdf_doc);
    FPDF_DestroyLibrary();
}
