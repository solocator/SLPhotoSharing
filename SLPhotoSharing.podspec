Pod::Spec.new do |s|

  s.name         = "SLPhotoSharing"
  s.version      = "1.0.1"
  s.summary      = "Sharing photos from Solocator"
  s.description  = "Sharing photos from Solocator"
  s.homepage     = "http://solocator.com/"
  s.license      = "MIT"
  s.author             = { "" => "" }
  s.platform     = :ios
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://github.com/solocator/SLPhotoSharing.git", :branch => "master", :tag => "1.0.1" }
  s.vendored_frameworks = "Framework/SLPhotoSharing.framework"
end
