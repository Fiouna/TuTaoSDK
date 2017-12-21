Pod::Spec.new do |s|
  s.name                = 'TuTaoSDK'
  s.version             = '0.1.0'
  s.summary             = 'TuTaoSDK for iOS'
  s.homepage            = 'http://www.picyoung.com/'
  s.license             = { :type => 'Commercial', :text => '©2015-2016 TuTao Info&Tech (Shanghai) Co.,Ltd.' }
  s.author              = { 'TuTao Team' => 'business@picyoung.com' }
  s.platform            = :ios, '9.0'
  s.source              = { :git => 'https://github.com/Fiouna/TuTaoSDK.git', :tag => s.version }
  s.requires_arc        = true
end
