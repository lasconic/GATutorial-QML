//=============================================================================
// Copyright (c) 2014 Nicolas Froment

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//=============================================================================

#import "iosanalytics.h"
#import "include/GAI.h"
#import "include/GAITracker.h"
#import "include/GAIDictionaryBuilder.h"
#import "include/GAIFields.h"

IosGoogleAnalytics::IosGoogleAnalytics() {

}

void IosGoogleAnalytics::initTracker() {
   // Optional: automatically send uncaught exceptions to Google Analytics.
   [GAI sharedInstance].trackUncaughtExceptions = YES;

   // Optional: set Google Analytics dispatch interval to e.g. 20 seconds.
   [GAI sharedInstance].dispatchInterval = 20;

   // Optional: set Logger to VERBOSE for debug information.
   // [[[GAI sharedInstance] logger] setLogLevel:kGAILogLevelVerbose];

   // Initialize tracker.
   id<GAITracker> tracker = [[GAI sharedInstance] trackerWithTrackingId:@"YOUR_TRACKER_ID"];

   NSString *appVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
   [tracker set:kGAIAppVersion value:appVersion];

   // Enable IDFA collection.
   [tracker setAllowIDFACollection: YES];
}

void IosGoogleAnalytics::sendHit(const QString &screenName) {
    id<GAITracker> tracker = [[GAI sharedInstance] defaultTracker];
    // Send a screen view
    [tracker send:[[[GAIDictionaryBuilder createAppView]
                    set:screenName.toNSString() forKey:kGAIScreenName] build]];
}

void IosGoogleAnalytics::sendEvent(const QString &category, const QString &action, const QString &label, long value) {
    id<GAITracker> tracker = [[GAI sharedInstance] defaultTracker];
    [tracker send:[[GAIDictionaryBuilder createEventWithCategory:category.toNSString()
                                                          action:action.toNSString()
                                                           label:label.toNSString()
                                                           value:[NSNumber numberWithLong:value]] build]];
}


