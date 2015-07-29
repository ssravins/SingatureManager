Pod::Spec.new do |s|

  s.name         = "SignatureManager"
  s.version      = "0.0.1"
  s.summary      = "Displaying custom Signature view."
  s.homepage     = "http://google.com"
  s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author       = { "Ravi" => "ssravins@yahoo.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/ssravins/SignatureViewTest.git", :tag => "0.0.1" }
  s.source_files  = "Sources/SignatureView/*.{h,m}"

end
