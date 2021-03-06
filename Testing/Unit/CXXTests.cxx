#include "SimpleITKTestHarness.h"

#include <sitkImage.h>
#include <sitkImageFileReader.h>
#include <sitkImageFileWriter.h>
#include <sitkHashImageFilter.h>

class CXX : public ExternalProgramRunner {
};


TEST_F(CXX,SimpleGaussian) {
  // Run the simple gaussian command line program
  std::string output = dataFinder.GetOutputFile ( "CXX.SimpleGaussian.nrrd" );
  std::vector<std::string> CommandLine;
  
  std::string exe = dataFinder.FindExecutable ( "SimpleGaussian" );
  ASSERT_TRUE ( dataFinder.FileExists ( exe ) ) << "Couldn't find " << exe;

  CommandLine.push_back ( exe );
  CommandLine.push_back ( dataFinder.GetFile ( "Input/RA-Short.nrrd" ).c_str() );
  CommandLine.push_back ( "2.0" );
  CommandLine.push_back ( output );

  // Run it!
  RunExecutable ( CommandLine, true );
  ASSERT_TRUE ( dataFinder.FileExists ( output ) );
  itk::simple::ImageFileReader reader;
  itk::simple::HashImageFilter hasher;
  itk::simple::Image* image;

  image = reader.SetFileName ( output ).Execute();
  ASSERT_TRUE ( image != NULL );
  ASSERT_TRUE ( image->GetImageBase().IsNotNull() ) << "Loaded output image";
  EXPECT_EQ ( "de64d7d8ebfa529581f57b8c603f3d656564284f", hasher.Execute ( image ) );
  delete image;
}

TEST_F(CXX,SimpleGaussianFunctional) {
  // Run the simple gaussian command line program
  std::string output = dataFinder.GetOutputFile ( "CXX.SimpleGaussianFunctional.nrrd" );
  std::vector<std::string> CommandLine;
  
  std::string exe = dataFinder.FindExecutable ( "SimpleGaussianFunctional" );
  ASSERT_TRUE ( dataFinder.FileExists ( exe ) ) << "Couldn't find " << exe;

  CommandLine.push_back ( exe );
  CommandLine.push_back ( dataFinder.GetFile ( "Input/RA-Short.nrrd" ).c_str() );
  CommandLine.push_back ( "2.0" );
  CommandLine.push_back ( output );

  // Run it!
  RunExecutable ( CommandLine, true );
  ASSERT_TRUE ( dataFinder.FileExists ( output ) );
  itk::simple::ImageFileReader reader;
  itk::simple::HashImageFilter hasher;
  itk::simple::Image* image;

  image = reader.SetFileName ( output ).Execute();
  ASSERT_TRUE ( image != NULL );
  ASSERT_TRUE ( image->GetImageBase().IsNotNull() ) << "Loaded output image";
  EXPECT_EQ ( "de64d7d8ebfa529581f57b8c603f3d656564284f", hasher.Execute ( image ) );
  delete image;
}

