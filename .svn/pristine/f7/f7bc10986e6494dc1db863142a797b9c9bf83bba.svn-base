//
//  STSignatureView.m
//  STSignature
//
//  Created by Sachin on 7/7/15.
//  Copyright (c) 2015 Sachin. All rights reserved.
//

#import "STSignatureView.h"


@implementation STSignatureView
{
    UILabel         *signatureLabel;
    UIBezierPath    *beizerPath;
    UIImage         *signatureImage;
    CGPoint         points[5];
    uint            control;
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    
    if (self) {
        
        self.backgroundColor = [UIColor whiteColor];
        [self setMultipleTouchEnabled:NO];
        beizerPath = [UIBezierPath bezierPath];
        [beizerPath setLineWidth:2.0];
        
        signatureLabel = [[UILabel alloc] initWithFrame:CGRectZero];
        signatureLabel.font = [UIFont fontWithName:@"HelveticaNeue" size:51];
        signatureLabel.textAlignment = NSTextAlignmentCenter;
        signatureLabel.alpha = 0.3;
        [self addSubview:signatureLabel];
        signatureLabel.translatesAutoresizingMaskIntoConstraints = NO;
        [self addConstraint:[NSLayoutConstraint constraintWithItem:signatureLabel attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterY multiplier:1.0 constant:0.0]];
        [self addConstraint:[NSLayoutConstraint constraintWithItem:signatureLabel attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterX multiplier:1.0 constant:0.0]];
    }
    return self;
}

- (void) setInitialLabelTextColor:(UIColor *)initialLabelTextColor{
    signatureLabel.textColor = initialLabelTextColor;
}

- (void)setInitialLabelText:(NSString *)initialLabelText{
    signatureLabel.text = initialLabelText;
}

- (void)drawRect:(CGRect)rect {
    // Drawing code
    [signatureImage drawInRect:rect];
    [beizerPath stroke];
    
    // Set initial color for drawing
    UIColor *fillColor = self.iniTialColour;
    [fillColor setFill];
    UIColor *strokeColor = self.iniTialColour;
    [strokeColor setStroke];
    [beizerPath stroke];
}

#pragma mark - UIView Touch Methods

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    if ([signatureLabel superview]){
        [signatureLabel removeFromSuperview];
    }
    control = 0;
    UITouch *touch = [touches anyObject];
    points[0] = [touch locationInView:self];
    
    CGPoint startPoint = points[0];
    CGPoint endPoint = CGPointMake(startPoint.x + 1.5, startPoint.y + 2);
    
    [beizerPath moveToPoint:startPoint];
    [beizerPath addLineToPoint:endPoint];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [touches anyObject];
    CGPoint touchPoint = [touch locationInView:self];
    control++;
    points[control] = touchPoint;
    
    if (control == 4)
    {
        points[3] = CGPointMake((points[2].x + points[4].x)/2.0, (points[2].y + points[4].y)/2.0);
        
        [beizerPath moveToPoint:points[0]];
        [beizerPath addCurveToPoint:points[3] controlPoint1:points[1] controlPoint2:points[2]];
        
        [self setNeedsDisplay];
        
        points[0] = points[3];
        points[1] = points[4];
        control = 1;
    }
    
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self drawBitmapImage];
    [self setNeedsDisplay];
    [beizerPath removeAllPoints];
    control = 0;
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self touchesEnded:touches withEvent:event];
}

#pragma mark - Bitmap Image Creation

- (void)drawBitmapImage
{
    UIGraphicsBeginImageContextWithOptions(self.bounds.size, YES, 0.0);
    
    if (!signatureImage)
    {
        UIBezierPath *rectpath = [UIBezierPath bezierPathWithRect:self.bounds];
        [[UIColor whiteColor] setFill];
        [rectpath fill];
    }
    [signatureImage drawAtPoint:CGPointZero];
    
    //Set final color for drawing
    UIColor *strokeColor = self.finalColour;
    [strokeColor setStroke];
    [beizerPath stroke];
    signatureImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
}

- (void)clearSignature
{
    signatureImage = nil;
    [self setNeedsDisplay];
    [self addSubview:signatureLabel];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:signatureLabel attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterY multiplier:1.0 constant:0.0]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:signatureLabel attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeCenterX multiplier:1.0 constant:0.0]];
}

#pragma mark - Get Signature image from given path

- (UIImage *)getSignatureImage {
    
    if([signatureLabel superview]){
        return nil;
    }
    UIGraphicsBeginImageContextWithOptions(self.bounds.size, NO, [UIScreen mainScreen].scale);
    [self drawViewHierarchyInRect:self.bounds afterScreenUpdates:YES];
    
    UIImage *signature_Image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return signature_Image;
}

@end
