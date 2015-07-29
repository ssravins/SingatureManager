//
//  STSignatureView.h
//  STSignature
//
//  Created by Sachin on 7/7/15.
//  Copyright (c) 2015 Sachin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface STSignatureView : UIView

@property (nonatomic, strong)UIColor        *iniTialColour;
@property (nonatomic, strong)UIColor        *finalColour;
@property (nonatomic, strong)NSString       *initialLabelText;
@property (nonatomic, strong)UIColor        *initialLabelTextColor;

- (UIImage *)getSignatureImage;
- (void)clearSignature;

@end
