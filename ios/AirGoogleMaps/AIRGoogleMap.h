//
//  AIRGoogleMap.h
//  AirMaps
//
//  Created by Gil Birman on 9/1/16.
//

#import <UIKit/UIKit.h>
#import <React/RCTComponent.h>
#import <React/RCTConvert+MapKit.h>
#import <GoogleMaps/GoogleMaps.h>
#import <MapKit/MapKit.h>
#import "AIRGMSMarker.h"

@interface AIRGoogleMap : GMSMapView

@property (nonatomic, assign) UIEdgeInsets customPadding;
// TODO: don't use MK region?
@property (nonatomic, assign) MKCoordinateRegion initialRegion;
@property (nonatomic, assign) MKCoordinateRegion region;
@property (nonatomic, assign) NSString *customMapStyleString;
@property (nonatomic, copy) RCTBubblingEventBlock onPress;
@property (nonatomic, copy) RCTBubblingEventBlock onLongPress;
@property (nonatomic, copy) RCTBubblingEventBlock onMarkerPress;
@property (nonatomic, copy) RCTBubblingEventBlock onChange;
@property (nonatomic, copy) RCTDirectEventBlock onRegionChange;
@property (nonatomic, copy) RCTDirectEventBlock onRegionChangeComplete;
@property (nonatomic, strong) NSMutableArray *markers;
@property (nonatomic, strong) NSMutableArray *polygons;
@property (nonatomic, strong) NSMutableArray *polylines;
@property (nonatomic, strong) NSMutableArray *circles;
@property (nonatomic, strong) NSMutableArray *tiles;

@property (nonatomic, assign) BOOL showsBuildings;
@property (nonatomic, assign) BOOL showsTraffic;
@property (nonatomic, assign) BOOL showsCompass;
@property (nonatomic, assign) BOOL scrollEnabled;
@property (nonatomic, assign) BOOL zoomEnabled;
@property (nonatomic, assign) BOOL rotateEnabled;
@property (nonatomic, assign) BOOL pitchEnabled;
@property (nonatomic, assign) BOOL showsUserLocation;

- (BOOL)didTapMarker:(GMSMarker *)marker;
- (void)didTapAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)didLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)didChangeCameraPosition:(GMSCameraPosition *)position;
- (void)idleAtCameraPosition:(GMSCameraPosition *)position;

+ (MKCoordinateRegion)makeGMSCameraPositionFromMap:(GMSMapView *)map andGMSCameraPosition:(GMSCameraPosition *)position;
+ (GMSCameraPosition*)makeGMSCameraPositionFromMap:(GMSMapView *)map andMKCoordinateRegion:(MKCoordinateRegion)region;

@end
