Pod::Spec.new do |s|

  s.name         = "SLPhotoSharing"
  s.version      = "2.2.1"
  s.summary      = "Sharing photos from Solocator"
  s.description  = "Sharing photos from Solocator"
  s.homepage     = "https://solocator.com/"
  s.license      = "MIT"
  s.author             = { "" => "" }
  s.platform     = :ios
  s.platform     = :ios, "12.0"
  s.source       = { :git => "https://github.com/solocator/SLPhotoSharing.git", :branch => "master", :tag => "2.2.1" }
  s.vendored_frameworks = "Framework/SLPhotoSharing.framework"
end
